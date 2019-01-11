//--------------------------------------------------------------------------------------
// LobbyPlayer.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

class CLobbyPlayer
{
public:
    CLobbyPlayer()
    {

    }

    CLobbyPlayer(const std::wstring& strDisplayName, byte shipColor, byte shipVariant, bool bIsReady)
    {
        m_strDisplayName = strDisplayName;
        m_shipColor = shipColor;
        m_shipVariant = shipVariant;
        m_bIsReady = bIsReady;
    }

    const std::wstring& GetDisplayName() const
    {
        return m_strDisplayName;
    }

    const byte ShipColor() const
    {
        return m_shipColor;
    }

    const byte ShipVariant() const
    {
        return m_shipVariant;
    }

    const bool IsReady() const
    {
        return m_bIsReady;
    }

private:
    std::wstring m_strDisplayName;
    byte m_shipColor;
    byte m_shipVariant;
    bool m_bIsReady;
};