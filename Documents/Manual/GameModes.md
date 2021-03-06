## Game Modes

### Initialization

1. Set the Initial Actors and their locations for your game mode. This will spawn initial units for each player at their player start as soon as the game starts.

### Game Over

1. Optionally, set the Defeat Condition Actor Classes for your RTSGameMode. This will check whether any actors of the specified types exist for a player whenever he or she loses a unit. If no actor of the specified type remains, the player is defeated.

_In that case, the game mode will raise the OnPlayerDefeated event to be overridden in subclasses (either blueprint or C++). Note that it is up to you to define how defeated players should be handled, and if/when the game is over, e.g. whether you've making a 1v1, FFA or team game._
