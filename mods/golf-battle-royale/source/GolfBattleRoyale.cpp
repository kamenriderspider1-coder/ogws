#include "GolfBattleRoyale.h"

namespace GolfBattleRoyale {

MatchManager::MatchManager() {
    Reset();
}

void MatchManager::Reset() {
    int i;
    mPhase = Phase_Lobby;
    mWinnerIndex = -1;
    for (i = 0; i < MaxPlayers; ++i) {
        mPlayers[i].status = Player_Inactive;
        mPlayers[i].health = StartingHealth;
        mPlayers[i].score = 0;
    }
}

bool MatchManager::AddPlayer(int playerIndex) {
    if (mPhase != Phase_Lobby || playerIndex < 0 ||
        playerIndex >= MaxPlayers ||
        mPlayers[playerIndex].status != Player_Inactive) {
        return false;
    }
    mPlayers[playerIndex].status = Player_Alive;
    mPlayers[playerIndex].health = StartingHealth;
    mPlayers[playerIndex].score = 0;
    return true;
}

bool MatchManager::StartMatch() {
    if (mPhase != Phase_Lobby || GetActivePlayerCount() < 2) {
        return false;
    }
    mPhase = Phase_Active;
    return true;
}

bool MatchManager::DamagePlayer(int playerIndex, int damage) {
    if (mPhase != Phase_Active || playerIndex < 0 ||
        playerIndex >= MaxPlayers || damage <= 0 ||
        mPlayers[playerIndex].status != Player_Alive) {
        return false;
    }

    mPlayers[playerIndex].health -= damage;
    if (mPlayers[playerIndex].health <= 0) {
        mPlayers[playerIndex].health = 0;
        mPlayers[playerIndex].status = Player_Eliminated;
        FinishIfOnePlayerRemains();
    }
    return true;
}

bool MatchManager::EliminatePlayer(int playerIndex) {
    if (mPhase != Phase_Active || playerIndex < 0 ||
        playerIndex >= MaxPlayers ||
        mPlayers[playerIndex].status != Player_Alive) {
        return false;
    }

    mPlayers[playerIndex].health = 0;
    mPlayers[playerIndex].status = Player_Eliminated;
    FinishIfOnePlayerRemains();
    return true;
}

void MatchManager::FinishIfOnePlayerRemains() {
    int activeCount = GetActivePlayerCount();
    int i;

    if (activeCount <= 1) {
        mWinnerIndex = -1;
        if (activeCount == 1) {
            for (i = 0; i < MaxPlayers; ++i) {
                if (mPlayers[i].status == Player_Alive) {
                    mWinnerIndex = i;
                    break;
                }
            }
        }
        mPhase = Phase_Finished;
    }
}

MatchPhase MatchManager::GetPhase() const {
    return mPhase;
}

PlayerStatus MatchManager::GetPlayerStatus(int playerIndex) const {
    if (playerIndex < 0 || playerIndex >= MaxPlayers) {
        return Player_Inactive;
    }
    return mPlayers[playerIndex].status;
}

int MatchManager::GetPlayerHealth(int playerIndex) const {
    if (playerIndex < 0 || playerIndex >= MaxPlayers) {
        return 0;
    }
    return mPlayers[playerIndex].health;
}

int MatchManager::GetActivePlayerCount() const {
    int count = 0;
    int i;
    for (i = 0; i < MaxPlayers; ++i) {
        if (mPlayers[i].status == Player_Alive) {
            ++count;
        }
    }
    return count;
}

int MatchManager::GetWinnerIndex() const {
    return mWinnerIndex;
}

} // namespace GolfBattleRoyale
