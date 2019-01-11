//--------------------------------------------------------------------------------------
// ParticleManager.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "ParticleManager.h"

using namespace ThunderRumble;

Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::Update(float, float, float, float)
{
}

ParticleCache::ParticleCache(int)
{
}

ParticleCache::~ParticleCache()
{
}

void ParticleCache::Reset()
{
}

std::shared_ptr<Particle> ParticleCache::GetNextParticle()
{
    return nullptr;
}

void ParticleCache::ReleaseParticle(std::shared_ptr<Particle>)
{
}


ParticleSystem::ParticleSystem()
{
}

ParticleSystem::~ParticleSystem()
{
}

std::shared_ptr<ParticleSystem> ParticleSystem::Clone()
{
    return nullptr;
}

void ParticleSystem::Initialize()
{
}

void ParticleSystem::Reset()
{
}

void ParticleSystem::Update(float elapsedTime)
{
}

void ParticleSystem::Draw(std::shared_ptr<RenderContext>)
{
}

void ParticleSystem::Stop(bool)
{
}

void ParticleSystem::GenerateParticles(float)
{
}

void ParticleSystem::UpdateParticles(float)
{
}

void ParticleSystem::InitializeParticle(std::shared_ptr<Particle>)
{
}

ParticleEffect::ParticleEffect()
{
}

ParticleEffect::~ParticleEffect()
{
}

std::shared_ptr<ParticleEffect> ParticleEffect::Clone()
{
    return nullptr;
}

void ParticleEffect::Initialize()
{
}

void ParticleEffect::Reset()
{
}

void ParticleEffect::Update(float)
{
}

void ParticleEffect::Draw(std::shared_ptr<RenderContext>, SpriteBlendMode)
{
}

void ParticleEffect::Stop(bool)
{
}

void ParticleEffect::SetPosition(DirectX::SimpleMath::Vector2)
{
}

void ParticleEffect::SetFollowOffset(DirectX::SimpleMath::Vector2)
{
}

ParticleEffectManager::ParticleEffectManager()
{
}

ParticleEffectManager::~ParticleEffectManager()
{
}

void ParticleEffectManager::Update(float)
{
}

void ParticleEffectManager::Draw(std::shared_ptr<RenderContext>, SpriteBlendMode)
{
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::SpawnEffect(ParticleEffectType, DirectX::SimpleMath::Vector2)
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::SpawnEffect(ParticleEffectType, std::shared_ptr<GameplayObject>)
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::SpawnEffect(ParticleEffectType, DirectX::SimpleMath::Vector2, std::shared_ptr<GameplayObject>)
{
    return nullptr;
}

void ParticleEffectManager::RegisterParticleEffect(ParticleEffectType, std::function<std::shared_ptr<ParticleEffect>(void)>, int)
{
}

void ParticleEffectManager::UnregisterParticleEffect(ParticleEffectType)
{
}



// Particle effect factory methods.
// These replace the XML files that the XNA version of NetRumble deserialized.
// You shouldn't directly create these effects, but instead use these functions with the ParticleEffectManager::RegisterParticleEffect function.

std::shared_ptr<ParticleEffect> ParticleEffectManager::CreateLaserExplosionEffect()
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::CreateRocketExplosionEffect()
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::CreateRocketTrailEffect()
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::CreateShipExplosionEffect()
{
    return nullptr;
}

std::shared_ptr<ParticleEffect> ParticleEffectManager::CreateShipSpawnEffect()
{
    return nullptr;
}
