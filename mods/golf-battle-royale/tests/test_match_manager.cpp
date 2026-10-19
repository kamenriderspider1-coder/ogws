#include "../source/GolfBattleRoyale.h"
#include <assert.h>

using namespace GolfBattleRoyale;

int main() {
    MatchManager match;
    assert(match.GetPhase() == Phase_Lobby);
    assert(match.GetActivePlayerCount() == 0);
    assert(match.GetWinnerIndex() == -1);
    assert(!match.StartMatch());

    assert(match.AddPlayer(0));
    assert(match.AddPlayer(1));
    assert(!match.AddPlayer(0));
    assert(!match.AddPlayer(-1));
    assert(!match.AddPlayer(4));
    assert(match.GetActivePlayerCount() == 2);
    assert(match.GetPlayerHealth(0) == MatchManager::StartingHealth);
    assert(match.StartMatch());
    assert(match.GetPhase() == Phase_Active);
    assert(!match.AddPlayer(2));

    assert(!match.DamagePlayer(0, 0));
    assert(!match.DamagePlayer(0, -5));
    assert(match.DamagePlayer(0, 35));
    assert(match.GetPlayerHealth(0) == 65);
    assert(match.GetPlayerStatus(0) == Player_Alive);

    assert(match.DamagePlayer(0, 65));
    assert(match.GetPlayerHealth(0) == 0);
    assert(match.GetPlayerStatus(0) == Player_Eliminated);
    assert(match.GetActivePlayerCount() == 1);
    assert(match.GetPhase() == Phase_Finished);
    assert(match.GetWinnerIndex() == 1);
    assert(!match.DamagePlayer(1, 1));
    assert(!match.EliminatePlayer(1));

    match.Reset();
    assert(match.GetPhase() == Phase_Lobby);
    assert(match.GetWinnerIndex() == -1);
    assert(match.AddPlayer(0));
    assert(match.AddPlayer(1));
    assert(match.AddPlayer(2));
    assert(match.AddPlayer(3));
    assert(!match.AddPlayer(4));
    assert(match.StartMatch());
    assert(match.EliminatePlayer(0));
    assert(match.EliminatePlayer(1));
    assert(match.EliminatePlayer(2));
    assert(match.GetWinnerIndex() == 3);
    return 0;
}
