#include <stdafx.h>

#include <playfab/PlayFabPluginManager.h>
#include <playfab/PlayFabHttp.h>

namespace PlayFab
{
    PlayFabPluginManager& PlayFabPluginManager::GetInstance()
    {
        static PlayFabPluginManager instance;
        return instance;
    }

    PlayFabPluginManager::PlayFabPluginManager()
    {
    }

    void PlayFabPluginManager::SetPlugin(std::shared_ptr<IPlayFabPlugin> plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        GetInstance().SetPluginInternal(std::move(plugin), contract, instanceName);
    }

    void PlayFabPluginManager::SetPluginInstance(std::shared_ptr<IPlayFabPlugin> plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        SetPluginInternal(std::move(plugin), contract, instanceName);
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::GetPluginInternal(const PlayFabPluginContract contract, const std::string& instanceName)
    {
        const auto key = std::make_pair(contract, instanceName);
        auto pluginEntry = plugins.find(key);
        if (pluginEntry == plugins.end())
        {
            // Requested plugin is not in the cache, create the default one
            std::shared_ptr<IPlayFabPlugin> pluginPtr = nullptr;
            switch (contract)
            {
            case PlayFabPluginContract::PlayFab_Serializer:
                pluginPtr = CreatePlayFabSerializerPlugin();
                break;
            case PlayFabPluginContract::PlayFab_Transport:
                pluginPtr = CreatePlayFabTransportPlugin();
                break;
            default:
                throw std::runtime_error("This contract is not supported");
                break;
            }

            plugins.insert({ key, pluginPtr });
            return pluginPtr;
        }
        else
        {
            return pluginEntry->second;
        }
    }

    void PlayFabPluginManager::SetPluginInternal(std::shared_ptr<IPlayFabPlugin> plugin, const PlayFabPluginContract contract, const std::string& instanceName)
    {
        const auto key = std::make_pair(contract, instanceName);
        auto pluginEntry = plugins.find(key);
        if (pluginEntry == plugins.end())
        {
            plugins.insert({ key, std::move(plugin) });
        }
        else
        {
            plugins.erase(key);
            plugins.insert({ key, std::move(plugin) });
        }
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::CreatePlayFabSerializerPlugin()
    {
        return std::make_shared<IPlayFabSerializerPlugin>();
    }

    std::shared_ptr<IPlayFabPlugin> PlayFabPluginManager::CreatePlayFabTransportPlugin()
    {
        return IPlayFabHttp::GetPtr();
    }
}
