//--------------------------------------------------------------------------------------
// CollisionManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "Manager.h"
#include "BatchRemovalCollection.h"

namespace ThunderRumble
{

    class GameplayObject;

    struct CollisionResult
    {
        float                           Distance;
        DirectX::SimpleMath::Vector2               Normal;
        std::shared_ptr<GameplayObject> GameplayObject;

        bool operator<(const CollisionResult &rhs) const { return Distance < rhs.Distance; }
    };

    class CollisionManager : public Manager
    {
    public:
        BatchRemovalCollection<std::shared_ptr<GameplayObject>>* Collection();
        RECT Dimensions();
        void SetDimensions(RECT dimensions);
        std::vector<RECT>& Barriers();
        void Update(float elapsedTime);
        void Collide(std::shared_ptr<GameplayObject> gameplayObject, const DirectX::SimpleMath::Vector2 &movement);
        DirectX::SimpleMath::Vector2 FindSpawnPoint(std::shared_ptr<GameplayObject> gameplayObject, float radius);
        void Explode(std::shared_ptr<GameplayObject> source, std::shared_ptr<GameplayObject> target, float damageAmount, const DirectX::SimpleMath::Vector2 &position, float damageRadius, bool damageOwner);

    private:
        // The ratio of speed to damage applied, for explosions.
        const float speedDamageRatio = 0.5f;

        // The number of times that the FindSpawnPoint method will try to find a point.
        const int findSpawnPointAttempts = 25;

        DirectX::SimpleMath::Vector2 MoveAndCollide(std::shared_ptr<GameplayObject> gameplayObject, const DirectX::SimpleMath::Vector2 &movement);
        void AdjustVelocities(std::shared_ptr<GameplayObject> actor1, std::shared_ptr<GameplayObject> actor2);

        std::shared_ptr<BatchRemovalCollection<std::shared_ptr<GameplayObject>>> _collection;
        RECT _dimensions;
        std::vector<RECT> _barriers;
        std::vector<CollisionResult> _collisionResults;
        std::mutex _lock;
    };

}
