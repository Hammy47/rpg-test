#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Player and Monster stats
	char playerName[10];
	int playerHP = 250;
	int playerSTR = 20;
	int playerDEX = 50;

	const char spider = "Spider";
	const int spiderHP = 60;
	const int spiderSTR = 10;
	const int spiderDEX = 50;

	const char goblin = "Goblin";
	const int goblinHP = 100;
	const int goblinSTR = 40;
	const int goblinDEX = 5;

	const char scorpion = "Scorpion";
	const int scorpionHP = 100;
	const int scorpionSTR = 0;
	const int scorpionDEX = 20;

	const char dragon = "Dragon";
	const int dragonHP = 400;
	const int dragonSTR = 50;
	const int dragonDEX = 33;

	const char vampire = "Vampire";
	const int vampireHP = 80;
	const int vampireSTR = 10;
	const int vampireDEX = 15;

	const char bandit = "Bandit";
	const int banditHP = 90;
	const int banditSTR = 15;
	const int banditDEX = 20;

	const char giantFrog = "Giant Frog";
	const int giantFrogHP = 250;
	const int giantFrogSTR = 15;
	const int giantFrogDEX = 0;

	// Player actions
	char playerChoice;
	char playerAction;

	// Combat Start
	int enemyHP;
	int enemySTR;
	int enemyDEX;
	int enemyDrop;
	int rounds;

	// Combat looping
	int hit;
	int enemyHit;
	int enemyRng;
	int potionHeal;

	// Misc Combat
	int vampireHeal;

	// Stats
	int forestCount;
	int goblinKills;
	int banditKills;
	int vampireKills;
	int giantFrogKills;

	// Consumables
	int playerPotions = 3;
	int spiderWeb = 0;
	int scorpionPoison = 0;

	// Quest Items
	int keys = 0;
	int mapA = 0;
	int mapB = 0;
	int theEnd = 0;
	int vampireBlood = 0;
	int banditHead = 0;
	int giantFrogTongue = 0;

	// RNG
	time_t t;
	srand((unsigned)time(&t));

	// Game
	printf("Every new beginning comes from some other beginning\'s end.\n"
		"				-Marcus Annaeus Seneca\n\n\n");
	printf("A new moon turns, you decide it's finally time to begin your adventure.\n"
		"What is your name? ");
	scanf("%s", playerName);
	printf("%s? A bloody fine name.\n\n", playerName);
	printf("You wave goodbye to your family and friends as you leave town.\n"
		"With only an old iron sword and a few health potions, you continue on.\n");
	do {
		// HOME (NO MATS)
		if (mapA >= 1 && mapB >= 1 && keys >= 1)
		{
			printf("\nAs the sun rises at your camp, you have to decide what you're planning on doing today.\n"
				"+--------+---------+\n"
				"|  REST  |  CAVES  |\n"
				"+--------+---------+\n"
				"| FOREST | BARRENS |\n"
				"+--------+---------+\n");
			printf("After acquiring both map fragments, as well as a key,\n"
				"you believe you might have found ANCIENT RUINS.\n");
			scanf(" %c", &playerChoice);
		}
		// HOME (MATS)
		else {
			printf("\nAs the sun rises at your camp, you have to decide what you're planning on doing today.\n"
				"+--------+---------+\n"
				"|  REST  |  CAVES  |\n"
				"+--------+---------+\n"
				"| FOREST | BARRENS |\n"
				"+--------+---------+\n");
			scanf(" %c", &playerChoice);
		}
		if (playerChoice != 'R' && playerChoice != 'C' && playerChoice != 'F' && playerChoice != 'B' && playerChoice != 'A')
		{
			printf("ERROR: Please select an option from the table.\n");
		}
		// REST
		else if (playerChoice == 'R')
		{
			if (playerHP >= 250)
			{
				printf("Your HP is already full!\n");
			}
			else if (playerHP < 250)
			{
				printf("You have rested, and have healed for 100 HP!\n");
				playerHP = playerHP + 100;
				printf("Current HP: %d\n", playerHP);
			}
		}
		// CAVES
		else if (playerChoice == 'C')
		{
			rounds = 0;
			enemyHP = spiderHP;
			enemySTR = spiderSTR;
			enemyDEX = spiderDEX;
			enemyDrop = rand() % 2;
			printf(
				"You enter the caves, finding a famished spider.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerPotions > 0)
					{
						printf("You have drank a health potion, healing 150HP\n");
						playerHP = playerHP + 150;
						playerPotions--;
						printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
					}
					else
					{
						printf("Player is out of potions!\n");
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY TURN
				if (enemyHit > playerDEX)
				{
					printf("\nThe spider has bit you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
				}
				else
				{
					printf("\nYou evaded the spiders attack!"
						"\nYour HP remains at %d\n", playerHP);
				}
			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				printf(
					"\nYou have slain the spider, looting the following:\n"
					"Health potion x1\n"
					"Otherworldly key x1\n"
					"Spider web x%d\n", enemyDrop + 1
				);
				playerPotions++;
				keys++;
				spiderWeb = spiderWeb + enemyDrop;
				spiderWeb++;
			}
		}
		// BARRENS
		else if (playerChoice == 'B')
		{
			rounds = 0;
			enemyHP = scorpionHP;
			enemySTR = scorpionSTR;
			enemyDEX = scorpionDEX;
			enemyDrop = rand() % 2;
			printf(
				"You enter the barren wasteland, finding a furious scorpion.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the spider! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerPotions > 0)
					{
						printf("You have drank a health potion, healing 150HP\n");
						playerHP = playerHP + 150;
						playerPotions--;
						printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
					}
					else
					{
						printf("Player is out of potions!\n");
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY ATTACK
				enemySTR = (rounds * 5+5);
				if (enemyHit > playerDEX)
				{
					printf("\nThe scorpion has pierced you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
				}
				else
				{
					printf("\nYou evaded the scorpions attack!"
						"\nYour HP remains at %d\n", playerHP);
				}
			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				printf(
					"\nYou have slain the scorpion, looting the following:\n"
					"Health potion x1\n"
					"Map Fragment B x1\n"
					"Scorpion Poison x%d\n", enemyDrop + 1
				);
				playerPotions++;
				mapB++;
				scorpionPoison = scorpionPoison + enemyDrop;
				scorpionPoison++;
			}
		}
		// FOREST
		else if (playerChoice == 'F')
		{
			enemyRng = rand() % 100;
			printf("\n%d\n", enemyRng);
			// Goblin
			if (enemyRng >= 0 && enemyRng < 25) {
				rounds = 0;
				enemyHP = goblinHP;
				enemySTR = goblinSTR;
				enemyDEX = goblinDEX;
				enemyDrop = rand() % 2;
				printf(
					"You enter the forest, finding a defensive Goblin.\n"
					"You know only one of you is leaving alive.\n"
					"What do you do?\n");
				do
				{
					rounds++;
					hit = rand() % 100;
					enemyHit = rand() % 100;
					printf("\nRound %d", rounds);
					printf(
						"\n+---------------------+\n"
						"|        ATTACK       |\n"
						"+----------+----------+\n"
						"|  POTION  |   RUN    |\n"
						"+----------+----------+\n"
					);
					scanf(" %c", &playerAction);
					if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
					{
						printf("\nERROR: PLEASE ENTER AN ACTION\n");
					}
					// ATTACK
					else if (playerAction == 'A')
					{
						if (hit > enemyDEX)
						{
							if (spiderWeb > 0 && scorpionPoison > 0)
							{
								printf("You have struck the goblin! Dealing %d damage!\n", playerSTR + 10);
								printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
									"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
								enemyHP = enemyHP - (playerSTR + 10);
								printf("Enemy HP has been reduced to %d!\n", enemyHP);
								spiderWeb--;
								scorpionPoison--;
							}
							else if (spiderWeb > 0 && scorpionPoison == 0)
							{
								printf("You have struck the goblin! Dealing %d damage!\n", playerSTR);
								printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
								enemyHP = enemyHP - playerSTR;
								enemyDEX = enemyDEX - 5;
								printf("Enemy HP has been reduced to %d!\n", enemyHP);
								spiderWeb--;
							}
							else if (spiderWeb == 0 && scorpionPoison > 0)
							{
								printf("You have struck the goblin! Dealing %d damage!\n", playerSTR + 10);
								printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
								enemyHP = enemyHP - (playerSTR + 10);
								printf("Enemy HP has been reduced to %d!\n", enemyHP);
								scorpionPoison--;
							}
							else
							{
								printf("You have struck the goblin! Dealing %d damage!\n", playerSTR);
								enemyHP = enemyHP - playerSTR;
								printf("Enemy HP has been reduced to %d!\n", enemyHP);
							}
						}
						else
						{
							printf("The enemy has evaded your attack!\n"
								"Enemy HP remains at %d!", enemyHP);
						}
					}
					// POTION
					else if (playerAction == 'P')
					{
						if (playerHP < 100)
						{
							potionHeal = 150;
						}
						else if (playerHP >= 100)
						{
							potionHeal = (250 - playerHP);
						}
						else
						{
							potionHeal;
						}
						printf("\n%d\n%d\n", playerHP, potionHeal);
						if (playerHP >= 250)
						{
							printf("Your HP is full!\n"
								"You remain at %d potions.", playerPotions);
						}
						else if (playerHP < 250)
						{
							if (playerPotions > 0)
							{
								printf("You have drank a health potion, healing %dHP\n", potionHeal);
								playerHP = playerHP + potionHeal;
								playerPotions--;
								printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
							}
							else
							{
								printf("Player is out of potions!\n");
							}
						}
					}
					// RUN
					else if (playerAction == 'R')
					{

					}
					// ENEMY TURN
					if (enemyHit > playerDEX)
					{
						printf("\nThe goblin has hit you for %d damage!", enemySTR);
						playerHP = playerHP - enemySTR;
						printf("\nYour current HP is %d\n", playerHP);
					}
					else
					{
						printf("\nYou evaded the goblins attack!"
							"\nYour HP remains at %d\n", playerHP);
					}

				} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
				// COMBAT END
				if (playerHP <= 0)
				{
					printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
						"You have died.\n"
						"GAME OVER.\n");
				}
				else if (playerAction == 'R')
				{
					printf("\nYou have run away, back to your camp.\n");
				}
				else if (enemyHP <= 0)
				{
					printf(
						"\nYou have slain the goblin, looting the following:\n"
						"Health potion x1\n"
						"Map Fragment A x1\n"
						"Bonus health potion x%d\n", enemyDrop + 1
					);
					playerPotions++;
					mapA++;
					playerPotions = playerPotions + enemyDrop;
					playerPotions++;

				}
			}
			// Vampire
			else if (enemyRng >= 25 && enemyRng < 50)
			{
			rounds = 0;
			enemyHP = vampireHP;
			enemySTR = vampireSTR;
			enemyDEX = vampireDEX;
			enemyDrop = rand() % 2;
			printf(
				"You enter the forest, finding a thirsty vampire.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				vampireHeal = enemySTR / 2;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the vampire! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the vampire! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the vampire! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the vampire! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerHP < 100)
					{
						potionHeal = 150;
					}
					else if (playerHP >= 100)
					{
						potionHeal = (250 - playerHP);
					}
					printf("\n%d\n%d\n", playerHP, potionHeal);
					if (playerHP >= 250)
					{
						printf("Your HP is full!\n"
							"You remain at %d potions.", playerPotions);
					}
					else if (playerHP < 250)
					{
						if (playerPotions > 0)
						{
							printf("You have drank a health potion, healing %dHP\n", potionHeal);
							playerHP = playerHP + potionHeal;
							playerPotions--;
							printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
						}
						else
						{
							printf("Player is out of potions!\n");
						}
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY TURN
				if (enemyHit > playerDEX)
				{
					printf("\nThe vampire has hit you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
					printf("\nThanks to it's unique ability, it healed for %d!\n", vampireHeal);
					enemyHP = enemyHP + vampireHeal;
					printf("It's HP is now %d\n", enemyHP);
				}
				else
				{
					printf("\nYou evaded the vampires attack!"
						"\nYour HP remains at %d\n", playerHP);
				}

			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				printf(
					"\nYou have slain the vampire, looting the following:\n"
					"Health potion x1\n"
					"Vampire blood x1\n"
					"Bonus health potion x%d\n", enemyDrop + 1
				);
				playerPotions++;
				vampireBlood++;
				playerPotions = playerPotions + enemyDrop;
				playerPotions++;

			}
			}
			// Bandit
			else if (enemyRng >= 50 && enemyRng < 75)
			{
			rounds = 0;
			enemyHP = banditHP;
			enemySTR = banditSTR;
			enemyDEX = banditDEX;
			enemyDrop = rand() % 2;
			printf(
				"You enter the forest, finding a mischievous bandit.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the bandit! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the bandit! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the bandit! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the bandit! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerHP < 100)
					{
						potionHeal = 150;
					}
					else if (playerHP >= 100)
					{
						potionHeal = (250 - playerHP);
					}
					printf("\n%d\n%d\n", playerHP, potionHeal);
					if (playerHP >= 250)
					{
						printf("Your HP is full!\n"
							"You remain at %d potions.", playerPotions);
					}
					else if (playerHP < 250)
					{
						if (playerPotions > 0)
						{
							printf("You have drank a health potion, healing %dHP\n", potionHeal);
							playerHP = playerHP + potionHeal;
							playerPotions--;
							printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
						}
						else
						{
							printf("Player is out of potions!\n");
						}
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY TURN
				if (enemyHit > playerDEX)
				{
					printf("\nThe bandit has hit you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
				}
				else
				{
					printf("\nYou evaded the bandits attack!"
						"\nYour HP remains at %d\n", playerHP);
				}

			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				printf(
					"\nYou have slain the bandit, looting the following:\n"
					"Health potion x1\n"
					"Bandit head x1\n"
					"Bonus health potion x%d\n", enemyDrop + 1
				);
				playerPotions++;
				banditHead++;
				playerPotions = playerPotions + enemyDrop;
				playerPotions++;

			}
			}
			// Giant Frog
			else if (enemyRng >= 75)
			{
			rounds = 0;
			enemyHP = giantFrogHP;
			enemySTR = giantFrogSTR;
			enemyDEX = giantFrogDEX;
			enemyDrop = rand() % 2;
			printf(
				"You enter the forest, finding a Giant Frog.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the Giant Frog! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the Giant Frog! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the Giant Frog! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the Giant Frog! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerHP < 100)
					{
						potionHeal = 150;
					}
					else if (playerHP >= 100)
					{
						potionHeal = (250 - playerHP);
					}
					printf("\n%d\n%d\n", playerHP, potionHeal);
					if (playerHP >= 250)
					{
						printf("Your HP is full!\n"
							"You remain at %d potions.", playerPotions);
					}
					else if (playerHP < 250)
					{
						if (playerPotions > 0)
						{
							printf("You have drank a health potion, healing %dHP\n", potionHeal);
							playerHP = playerHP + potionHeal;
							playerPotions--;
							printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
						}
						else
						{
							printf("Player is out of potions!\n");
						}
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY TURN
				if (enemyHit > playerDEX)
				{
					printf("\nThe Giant Frog has hit you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
				}
				else
				{
					printf("\nYou evaded the Giant Frogs attack!"
						"\nYour HP remains at %d\n", playerHP);
				}

			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				printf(
					"\nYou have slain the Giant Frog, looting the following:\n"
					"Health potion x1\n"
					"Giant Frog tongue x1\n"
					"Bonus health potion x%d\n", enemyDrop + 1
				);
				playerPotions++;
				giantFrogTongue++;
				playerPotions = playerPotions + enemyDrop;
				playerPotions++;

			}
			}
		}
		// ANCIENT RUINS (NO MATS)
		else if (playerChoice == 'A' && mapA == 0 && mapB == 0 && keys == 0)
		{
			printf("ERROR: Please select an option from the table.\n");
		}
		// ANCIENT RUINS
		else if (playerChoice == 'A' && mapA >= 1 && mapB >= 1 && keys >= 1)
		{
			rounds = 0;
			enemyHP = dragonHP;
			enemySTR = dragonSTR;
			enemyDEX = dragonDEX;
			printf(
				"You enter the ancient ruins, finding a confused but upset dragon.\n"
				"You know only one of you is leaving alive.\n"
				"What do you do?\n");
			do
			{
				rounds++;
				hit = rand() % 100;
				enemyHit = rand() % 100;
				printf("\nRound %d", rounds);
				printf(
					"\n+---------------------+\n"
					"|        ATTACK       |\n"
					"+----------+----------+\n"
					"|  POTION  |   RUN    |\n"
					"+----------+----------+\n"
				);
				scanf(" %c", &playerAction);
				if (!(playerAction == 'A' || playerAction == 'P' || playerAction == 'R'))
				{
					printf("\nERROR: PLEASE ENTER AN ACTION\n");
				}
				// ATTACK
				else if (playerAction == 'A')
				{
					if (hit > enemyDEX)
					{
						if (spiderWeb > 0 && scorpionPoison > 0)
						{
							printf("You have struck the dragon! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n"
								"Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
							scorpionPoison--;
						}
						else if (spiderWeb > 0 && scorpionPoison == 0)
						{
							printf("You have struck the dragon! Dealing %d damage!\n", playerSTR);
							printf("Thanks to your spider webbing, the enemy's DEX has been decreased by 5!\n");
							enemyHP = enemyHP - playerSTR;
							enemyDEX = enemyDEX - 5;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							spiderWeb--;
						}
						else if (spiderWeb == 0 && scorpionPoison > 0)
						{
							printf("You have struck the dragon! Dealing %d damage!\n", playerSTR + 10);
							printf("Thanks to your scorpion poisoning, your weapon has dealt an extra 10HP!\n");
							enemyHP = enemyHP - (playerSTR + 10);
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
							scorpionPoison--;
						}
						else
						{
							printf("You have struck the dragon! Dealing %d damage!\n", playerSTR);
							enemyHP = enemyHP - playerSTR;
							printf("Enemy HP has been reduced to %d!\n", enemyHP);
						}
					}
					else
					{
						printf("The enemy has evaded your attack!\n"
							"Enemy HP remains at %d!", enemyHP);
					}
				}
				// POTION
				else if (playerAction == 'P')
				{
					if (playerPotions > 0)
					{
						printf("You have drank a health potion, healing 150HP\n");
						playerHP = playerHP + 150;
						playerPotions--;
						printf("Current HP is %d, and you have %d potions remaining.\n", playerHP, playerPotions);
					}
					else
					{
						printf("Player is out of potions!\n");
					}
				}
				// RUN
				else if (playerAction == 'R')
				{

				}
				// ENEMY TURN
				if (enemyHit > playerDEX)
				{
					printf("\nThe dragon blew fire at you for %d damage!", enemySTR);
					playerHP = playerHP - enemySTR;
					printf("\nYour current HP is %d\n", playerHP);
				}
				else
				{
					printf("\nYou evaded the dragons attack!"
						"\nYour HP remains at %d\n", playerHP);
				}
			} while (playerAction != 'R' && enemyHP > 0 && playerHP > 0);
			// COMBAT END
			if (playerHP <= 0)
			{
				printf("\nYou put up a good fight, but in the end, it wasn't enough.\n"
					"You have died.\n"
					"GAME OVER.\n");
			}
			else if (playerAction == 'R')
			{
				printf("\nYou have run away, back to your camp.\n");
			}
			else if (enemyHP <= 0)
			{
				playerHP = playerHP - playerHP;
				theEnd++;
			}
		}
	} while (playerHP > 0);
	// ENDING
	if (theEnd = 1)
	{
		printf("\nAfter finally slaying the dragon, you continue on to it's hoard\n"
			"Within the ruins, you find such an extreme amount of gold\n"
			"that you and your kin will be wealthy for generations.\n\n"
			"You soon after decide to retire, seeking out a family.\n"
			"The end.");
	}
	// DEAD
	else
	{
	}
	return 0;
}