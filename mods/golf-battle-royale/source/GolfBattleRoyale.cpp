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
        mPlayers[i].item = Item_None;
        mPlayers[i].score = 0;
    }
}

bool MatchManager::AddPlayer(int playerIndex) {
    if (mPhase != Phase_Lobby || playerIndex < 0 || playerIndex >= MaxPlayers) {
        return false;
    }
    mPlayers[playerIndex].status = Player_Alive;
    mPlayers[playerIndex].item = Item_None;
    mPlayers[playerIndex].score = 0;
    return true;
}

bool MatchManager::StartMatch() {
    int activeCount = GetActivePlayerCount();
    if (mPhase != Phase_Lobby || activeCount < 2) {
        return false;
    }
    mPhase = Phase_Active;
    return true;
}

bool MatchManager::EliminatePlayer(int playerIndex) {
    if (mPhase != Phase_Active || playerIndex < 0 || playerIndex >= MaxPlayers) {
        return false;
    }
    if (mPlayers[playerIndex].status != Player_Alive) {
        return false;
    }

    mPlayers[playerIndex].status = Player_Eliminated;
    mPlayers[playerIndex].item = Item_None;

    if (GetActivePlayerCount() == 1) {
        int i;
        for (i = 0; i < MaxPlayers; ++i) {
            if (mPlayers[i].status == Player_Alive) {
                mWinnerIndex = i;
                break;
            }
        }
        mPhase = Phase_Finished;
    } else if (GetActivePlayerCount() == 0) {
        mWinnerIndex = -1;
        mPhase = Phase_Finished;
    }
    return true;
}

bool MatchManager::GiveItem(int playerIndex, ItemType item) {
    if (mPhase != Phase_Active || playerIndex < 0 || playerIndex >= MaxPlayers ||
        item == Item_None || mPlayers[playerIndex].status != Player_Alive) {
        return false;
    }
    mPlayers[playerIndex].item = item;
    return true;
}

bool MatchManager::ConsumeItem(int playerIndex, ItemType* outItem) {
    if (mPhase != Phase_Active || playerIndex < 0 || playerIndex >= MaxPlayers ||
        outItem == 0 || mPlayers[playerIndex].status != Player_Alive ||
        mPlayers[playerIndex].item == Item_None) {
        return false;
    }
    *outItem = mPlayers[playerIndex].item;
    mPlayers[playerIndex].item = Item_None;
    return true;
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
