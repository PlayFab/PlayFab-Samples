#pragma once

namespace PlayFab
{
    namespace ClientModels
    {
        struct PlayerProfileModel;
        struct PlayerProfileViewConstraints;
    }
}

// Class to format a PlayFab Player Profile
class PlayFabPlayerProfileSummary
{
public:
    PlayFabPlayerProfileSummary();

    PlayFabPlayerProfileSummary(
        const PlayFab::ClientModels::PlayerProfileViewConstraints &constraints,
        const PlayFab::ClientModels::PlayerProfileModel &profile);

    const std::wstring &GetFormatted() const
    {
        return m_formatted;
    }

private:
    std::wstring m_formatted;
};