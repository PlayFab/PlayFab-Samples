//--------------------------------------------------------------------------------------
// GameplayObject.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

namespace BumbleRumble
{
class RenderContext;

enum class GameplayObjectType
{
    Unknown,
    Ship,
    Asteroid,
    Projectile,
    PowerUp
};

class GameplayObject : public std::enable_shared_from_this<GameplayObject>
{
public:
    GameplayObject();
    virtual ~GameplayObject() = default;

    // Prevent copying.
    GameplayObject(GameplayObject const&) = delete;
    GameplayObject& operator= (GameplayObject const&) = delete;

    virtual void Initialize();
    virtual void Update(float elapsedTime);
    virtual void Draw(float elapsedTime, std::shared_ptr<RenderContext> renderContext, std::shared_ptr<DX::Texture> sprite, DirectX::XMVECTOR color);
    virtual bool OnTouch(std::shared_ptr<GameplayObject> target);
    virtual bool TakeDamage(std::shared_ptr<GameplayObject> source, float damageAmount);
    virtual void Die(std::shared_ptr<GameplayObject> source, bool cleanupOnly);

    // Since we don't have an "is" keyword in C++, objects must be honest and return back what type they are
    virtual GameplayObjectType GetType() const { return GameplayObjectType::Unknown; }

    inline uint32_t GetID() const { return m_uniqueID; }
    inline void SetID(uint32_t id) { m_uniqueID = id; } // careful, should only be called when told by host network message

    inline bool Active() const { return m_active; }

    DirectX::SimpleMath::Vector2 Position;
    float Rotation;
    float Radius;

    DirectX::SimpleMath::Vector2 Velocity;
    float Mass;
    bool CollidedThisFrame;

    float Life;
    
protected:
    bool m_active;

private:
    uint32_t m_uniqueID;
    static std::atomic_uint32_t s_nextUniqueID;
};

}
