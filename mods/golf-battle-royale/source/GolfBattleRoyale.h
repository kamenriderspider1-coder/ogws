#ifndef GOLF_BATTLE_ROYALE_H
#define GOLF_BATTLE_ROYALE_H

// Standalone rules prototype for the Wii Sports Golf Battle Royale mod.
// This is not connected to the Golf scene yet.
namespace GolfBattleRoyale {

enum MatchPhase {
    Phase_Lobby,
    Phase_Countdown,
    Phase_Active,
    Phase_Finished
};

enum PlayerStatus {
    Player_Inactive,
    Player_Alive,
    Player_Eliminated
};

enum ItemType {
    Item_None,
    Item_ExtraShot,
    Item_SlowOpponent,
    Item_Shield
};

struct PlayerSlot {
    PlayerStatus status;
    ItemType item;
    int score;
};

class MatchManager {
public:
    enum { MaxPlayers = 16 };

    MatchManager();

    void Reset();
    bool AddPlayer(int playerIndex);
    bool StartMatch();
    bool EliminatePlayer(int playerIndex);
    bool GiveItem(int playerIndex, ItemType item);
    bool ConsumeItem(int playerIndex, ItemType* outItem);

    MatchPhase GetPhase() const;
    PlayerStatus GetPlayerStatus(int playerIndex) const;
    int GetActivePlayerCount() const;
    int GetWinnerIndex() const;

private:
    MatchPhase mPhase;
    PlayerSlot mPlayers[MaxPlayers];
    int mWinnerIndex;
};

} // namespace GolfBattleRoyale

#endif
