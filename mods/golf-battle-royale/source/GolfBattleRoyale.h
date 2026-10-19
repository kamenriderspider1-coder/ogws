#ifndef GOLF_BATTLE_ROYALE_H
#define GOLF_BATTLE_ROYALE_H

// Standalone rules prototype for the Wii Sports Golf Battle Royale mod.
// Uses match rules only; it adds no custom items or game assets.
// Not yet connected to RPGolScene or the original player/session systems.
namespace GolfBattleRoyale {

enum MatchPhase {
    Phase_Lobby,
    Phase_Active,
    Phase_Finished
};

enum PlayerStatus {
    Player_Inactive,
    Player_Alive,
    Player_Eliminated
};

struct PlayerSlot {
    PlayerStatus status;
    int health;
    int score;
};

class MatchManager {
public:
    // Wii Sports supports up to four local players.
    enum { MaxPlayers = 4, StartingHealth = 100 };

    MatchManager();

    void Reset();
    bool AddPlayer(int playerIndex);
    bool StartMatch();
    bool DamagePlayer(int playerIndex, int damage);
    bool EliminatePlayer(int playerIndex);

    MatchPhase GetPhase() const;
    PlayerStatus GetPlayerStatus(int playerIndex) const;
    int GetPlayerHealth(int playerIndex) const;
    int GetActivePlayerCount() const;
    int GetWinnerIndex() const;

private:
    void FinishIfOnePlayerRemains();

    MatchPhase mPhase;
    PlayerSlot mPlayers[MaxPlayers];
    int mWinnerIndex;
};

} // namespace GolfBattleRoyale

#endif
