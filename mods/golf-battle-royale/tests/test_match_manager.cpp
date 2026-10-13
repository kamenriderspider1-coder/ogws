#include "../source/GolfBattleRoyale.h"
#include <assert.h>

using namespace GolfBattleRoyale;

int main() {
    MatchManager match;
    assert(match.GetPhase() == Phase_Lobby);
    assert(match.GetActivePlayerCount() == 0);
    assert(!match.StartMatch());

    assert(match.AddPlayer(0));
    assert(match.AddPlayer(1));
    assert(!match.AddPlayer(-1));
    assert(match.GetActivePlayerCount() == 2);
    assert(match.StartMatch());
    assert(match.GetPhase() == Phase_Active);

    assert(match.GiveItem(0, Item_Shield));
    ItemType item = Item_None;
    assert(match.ConsumeItem(0, &item));
    assert(item == Item_Shield);
    assert(!match.ConsumeItem(0, &item));

    assert(match.EliminatePlayer(0));
    assert(match.GetActivePlayerCount() == 1);
    assert(match.GetPhase() == Phase_Finished);
    assert(match.GetWinnerIndex() == 1);
    assert(!match.EliminatePlayer(1));

    match.Reset();
    assert(match.GetPhase() == Phase_Lobby);
    assert(match.GetWinnerIndex() == -1);
    return 0;
}
