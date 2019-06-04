#include <allegro5/allegro.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "Plane.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"

PlayScene* Plane::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
Plane::Plane() : Sprite("play/plane.png", -100, Engine::GameEngine::GetInstance().GetScreenHeight() / 2), stage(0), timeTicks(0) {
	for (int i = 1; i <= 10; i++) {
		bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/light-" + std::to_string(i) + ".png"));
	}
	shockwave = Engine::Resources::GetInstance().GetBitmap("play/shockwave.png");
	Velocity = Engine::Point(800, 0);
}
void Plane::Update(float deltaTime) {
	int phase;
	float scaleExp;
	switch (stage) {
	case 0:
		// Check if out of boundary.
		if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(-100, 0), PlayScene::GetClientSize())) {
			Position = PlayScene::GetClientSize() / 2;
			Velocity = Engine::Point();
			bmp = bmps[0];
			Size.x = GetBitmapWidth() * minScale;
			Size.y = GetBitmapHeight() * minScale;
			scale = 1.0f * minScale;
			stage++;
		}
		break;
	case 1:
		timeTicks += deltaTime;
		if (timeTicks >= timeSpanLight) {
			bmp = shockwave;
			stage++;
			AudioHelper::PlayAudio("shockwave.ogg");
			break;
		}
		scaleExp = ((timeSpanLight + timeSpanShockwave - timeTicks) * log2(minScale) + timeTicks * log2(maxScale)) / (timeSpanLight + timeSpanShockwave);
		scale = pow(2, scaleExp);
		Size.x = GetBitmapWidth() * scale;
		Size.y = GetBitmapHeight() * scale;
		CollisionRadius = shockWaveRadius * scale;
		phase = floor(timeTicks / timeSpanLight * bmps.size());
		bmp = bmps[phase];
		break;
	case 2:
		timeTicks += deltaTime;
		if (timeTicks >= timeSpanLight + timeSpanShockwave) {
			timeTicks = 0;
			stage++;
			break;
		}
		scaleExp = ((timeSpanLight + timeSpanShockwave - timeTicks) * log2(minScale) + timeTicks * log2(maxScale)) / (timeSpanLight + timeSpanShockwave);
		scale = pow(2, scaleExp);
		Size.x = GetBitmapWidth() * scale;
		Size.y = GetBitmapHeight() * scale;
		CollisionRadius = shockWaveRadius * scale;
		// Check if overlap with enemy.
		for (auto& it : getPlayScene()->EnemyGroup->GetObjects()) {
			Enemy* enemy = dynamic_cast<Enemy*>(it);
			if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius))
				enemy->Hit(INFINITY);
		}
		break;
	case 3:
		getPlayScene()->EffectGroup->RemoveObject(objectIterator);
		return;
	}
	Sprite::Update(deltaTime);
}
void Plane::Draw() const {
	unsigned int phase = floor(timeTicks / timeSpanLight * bmps.size());
	float phaseRatio = timeTicks / timeSpanLight * bmps.size() - phase;
	if (stage == 1 || stage == 2) {
		if (phase > 7 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 7].get(), al_map_rgba(0, 0, 255, 255 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 6 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 6].get(), al_map_rgba(0, 0, 255, 191 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 5 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 5].get(), al_map_rgba(0, 255, 0, 127 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 4 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 4].get(), al_map_rgba(255, 255, 255, phaseRatio * 63), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 3 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 3].get(), al_map_rgba(255, 0, 0, 63 - phaseRatio * 63), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 2 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 2].get(), al_map_rgba(255, 0, 0, 127 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}
		if (phase > 1 && phase < bmps.size()) {
			al_draw_tinted_scaled_rotated_bitmap(bmps[phase - 1].get(), al_map_rgba(0, 255, 0, 191 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
				Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
		}

	}
	if (stage == 1)
		al_draw_tinted_scaled_rotated_bitmap(bmp.get(), al_map_rgba(255, 255, 255, 255 - phaseRatio * 64), Anchor.x * GetBitmapWidth(), Anchor.y * GetBitmapHeight(),
			Position.x, Position.y, Size.x / GetBitmapWidth(), Size.y / GetBitmapHeight(), Rotation, 0);
	else {
		Sprite::Draw();
	}
}
