#ifndef GUARD_CONSTANTS_VARS_H
#define GUARD_CONSTANTS_VARS_H

#include "constants/vars_frlg.h"

#define VARS_START 0x4000

// temporary vars
// The first 0x10 vars are temporary--they are cleared every time a map is loaded.
#define TEMP_VARS_START            0x4000
#define VAR_TEMP_0                 (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                 (TEMP_VARS_START + 0x1)
#define VAR_TEMP_2                 (TEMP_VARS_START + 0x2)
#define VAR_TEMP_3                 (TEMP_VARS_START + 0x3) // Note: Used when the player checks a TV
#define VAR_TEMP_4                 (TEMP_VARS_START + 0x4)
#define VAR_TEMP_5                 (TEMP_VARS_START + 0x5)
#define VAR_TEMP_6                 (TEMP_VARS_START + 0x6)
#define VAR_TEMP_7                 (TEMP_VARS_START + 0x7)
#define VAR_TEMP_8                 (TEMP_VARS_START + 0x8)
#define VAR_TEMP_9                 (TEMP_VARS_START + 0x9)
#define VAR_TEMP_A                 (TEMP_VARS_START + 0xA)
#define VAR_TEMP_B                 (TEMP_VARS_START + 0xB)
#define VAR_TEMP_C                 (TEMP_VARS_START + 0xC)
#define VAR_TEMP_D                 (TEMP_VARS_START + 0xD)
#define VAR_TEMP_E                 (TEMP_VARS_START + 0xE)
#define VAR_TEMP_F                 (TEMP_VARS_START + 0xF)
#define TEMP_VARS_END              VAR_TEMP_F
#define NUM_TEMP_VARS              (TEMP_VARS_END - TEMP_VARS_START + 1)

// object gfx id vars
// These 0x10 vars are used to dynamically control a map object's sprite.
// For example, the rival's sprite id is dynamically set based on the player's gender.
// See VarGetObjectEventGraphicsId().
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
#define VAR_OBJ_GFX_ID_2           0x4012
#define VAR_OBJ_GFX_ID_3           0x4013
#define VAR_OBJ_GFX_ID_4           0x4014
#define VAR_OBJ_GFX_ID_5           0x4015
#define VAR_OBJ_GFX_ID_6           0x4016
#define VAR_OBJ_GFX_ID_7           0x4017
#define VAR_OBJ_GFX_ID_8           0x4018
#define VAR_OBJ_GFX_ID_9           0x4019
#define VAR_OBJ_GFX_ID_A           0x401A
#define VAR_OBJ_GFX_ID_B           0x401B
#define VAR_OBJ_GFX_ID_C           0x401C
#define VAR_OBJ_GFX_ID_D           0x401D
#define VAR_OBJ_GFX_ID_E           0x401E
#define VAR_OBJ_GFX_ID_F           0x401F

// general purpose vars
#define VAR_RECYCLE_GOODS                                0x4020
#define VAR_REPEL_STEP_COUNT                             0x4021
#define VAR_ICE_STEP_COUNT                               0x4022
#define VAR_STARTER_MON                                  0x4023 // STARTER_* below
#define STARTER_TURTWIG  0
#define STARTER_CHIMCHAR 1
#define STARTER_PIPLUP   2
#define VAR_MIRAGE_RND_H                                 0x4024
#define VAR_MIRAGE_RND_L                                 0x4025
#define VAR_SECRET_BASE_MAP                              0x4026
#define VAR_CYCLING_ROAD_RECORD_COLLISIONS               0x4027
#define VAR_CYCLING_ROAD_RECORD_TIME_L                   0x4028
#define VAR_CYCLING_ROAD_RECORD_TIME_H                   0x4029
#define VAR_FRIENDSHIP_STEP_COUNTER                      0x402A
#define VAR_POISON_STEP_COUNTER                          0x402B
#define VAR_RESET_RTC_ENABLE                             0x402C
#define VAR_ENIGMA_BERRY_AVAILABLE                       0x402D
#define VAR_WONDER_NEWS_STEP_COUNTER                     0x402E

#define VAR_FRONTIER_MANIAC_FACILITY                     0x402F
#define VAR_FRONTIER_GAMBLER_CHALLENGE                   0x4030
#define VAR_FRONTIER_GAMBLER_SET_CHALLENGE               0x4031
#define VAR_FRONTIER_GAMBLER_AMOUNT_BET                  0x4032
#define VAR_FRONTIER_GAMBLER_STATE                       0x4033

#define VAR_DEOXYS_ROCK_STEP_COUNT                       0x4034
#define VAR_DEOXYS_ROCK_LEVEL                            0x4035
#define VAR_PC_BOX_TO_SEND_MON                           0x4036
#define VAR_ABNORMAL_WEATHER_LOCATION                    0x4037
#define VAR_ABNORMAL_WEATHER_STEP_COUNTER                0x4038
#define VAR_SHOULD_END_ABNORMAL_WEATHER                  0x4039
#define VAR_FARAWAY_ISLAND_STEP_COUNTER                  0x403A
#define VAR_REGICE_STEPS_1                               0x403B
#define VAR_REGICE_STEPS_2                               0x403C
#define VAR_REGICE_STEPS_3                               0x403D
#define VAR_ALTERING_CAVE_WILD_SET                       0x403E
#define VAR_DISTRIBUTE_EON_TICKET                        0x403F // This var is read and written, but is always zero. The only way to obtain the Eon Ticket in Emerald is via Record Mixing
#define VAR_DAYS                                         0x4040
#define VAR_FANCLUB_FAN_COUNTER                          0x4041
#define VAR_FANCLUB_LOSE_FAN_TIMER                       0x4042
#define VAR_DEPT_STORE_FLOOR                             0x4043
#define VAR_TRICK_HOUSE_LEVEL                            0x4044
#define VAR_POKELOT_PRIZE_ITEM                           0x4045
#define VAR_NATIONAL_DEX                                 0x4046
#define VAR_SEEDOT_SIZE_RECORD                           0x4047
#define VAR_ASH_GATHER_COUNT                             0x4048
#define VAR_BIRCH_STATE                                  0x4049
#define VAR_CRUISE_STEP_COUNT                            0x404A
#define VAR_POKELOT_RND1                                 0x404B
#define VAR_POKELOT_RND2                                 0x404C
#define VAR_POKELOT_PRIZE_PLACE                          0x404D
#define VAR_TWINLEAF_TOWN_STATE                          0x404E
// @states Twinleaf intro arc, from waking up to owning a starter.
//    0  Starting state
//    1  Player has run into Barry out front of his house
//    2  Player has found Barry upstairs and watches him run out
//    3  Player has Barry join as a follower on Route 201
//    4  Player have entered Barry enter Lake Verity
//    5  Lake Verity cutscene
//    9  Player has chosen a starter
//   10  Player and Barry have left Lake Verity, walking back towards Twinleaf
//   11  Player and Barry encounter Rowan and Lucas/Dawn once more on Route 201
//   12  Player has caught Mom up to speed and has starter now
//   13  No op
//   14  Player has received Exp. Share from Mom and the Parcel for Barry from Barry's mom
#define VAR_LOTAD_SIZE_RECORD                            0x404F
#define VAR_LITTLEROOT_TOWN_STATE                        0x4050
#define VAR_OLDALE_TOWN_STATE                            0x4051
#define VAR_TWINLEAF_TOWN_PLAYER_HOUSE_STATE             0x4052
// @states Mom's scripted beats inside the player's house.
//    0  Starting state
//    1  Player has received running shoes.
//    2  Mom has warned player about tall grass on first exit
#define VAR_LAVARIDGE_TOWN_STATE                         0x4053
#define VAR_CURRENT_SECRET_BASE                          0x4054 // was probably allocated for VAR_FALLARBOR_TOWN_STATE at one point
#define VAR_VERDANTURF_TOWN_STATE                        0x4055 // Unused Var
#define VAR_PACIFIDLOG_TOWN_STATE                        0x4056 // Unused Var
#define VAR_PETALBURG_CITY_STATE                         0x4057
#define VAR_SLATEPORT_CITY_STATE                         0x4058
#define VAR_MAUVILLE_CITY_STATE                          0x4059 // Unused Var
#define VAR_RUSTBORO_CITY_STATE                          0x405A
#define VAR_FORTREE_CITY_STATE                           0x405B // Unused Var
#define VAR_LILYCOVE_CITY_STATE                          0x405C // Unused Var
#define VAR_MOSSDEEP_CITY_STATE                          0x405D
#define VAR_SOOTOPOLIS_CITY_STATE                        0x405E
#define VAR_EVER_GRANDE_CITY_STATE                       0x405F // Unused Var
#define VAR_ROUTE101_STATE                               0x4060
#define VAR_ROUTE102_STATE                               0x4061 // Unused Var
#define VAR_ROUTE103_STATE                               0x4062 // Unused Var
#define VAR_ROUTE104_STATE                               0x4063
#define VAR_ROUTE105_STATE                               0x4064 // Unused Var
#define VAR_ROUTE106_STATE                               0x4065 // Unused Var
#define VAR_ROUTE107_STATE                               0x4066 // Unused Var
#define VAR_ROUTE108_STATE                               0x4067 // Unused Var
#define VAR_ROUTE109_STATE                               0x4068 // Unused Var
#define VAR_ROUTE110_STATE                               0x4069
#define VAR_ROUTE111_STATE                               0x406A // Unused Var
#define VAR_ROUTE112_STATE                               0x406B // Unused Var
#define VAR_ROUTE113_STATE                               0x406C // Unused Var
#define VAR_ROUTE114_STATE                               0x406D // Unused Var
#define VAR_ROUTE115_STATE                               0x406E // Unused Var
#define VAR_ROUTE116_STATE                               0x406F
#define VAR_ROUTE117_STATE                               0x4070 // Unused Var
#define VAR_ROUTE118_STATE                               0x4071
#define VAR_ROUTE119_STATE                               0x4072
#define VAR_ROUTE120_STATE                               0x4073 // Unused Var
#define VAR_ROUTE121_STATE                               0x4074
#define VAR_ROUTE122_STATE                               0x4075 // Unused Var
#define VAR_ROUTE123_STATE                               0x4076 // Unused Var
#define VAR_ROUTE124_STATE                               0x4077 // Unused Var
#define VAR_ROUTE125_STATE                               0x4078 // Unused Var
#define VAR_ROUTE126_STATE                               0x4079 // Unused Var
#define VAR_ROUTE127_STATE                               0x407A // Unused Var
#define VAR_ROUTE128_STATE                               0x407B
#define VAR_ROUTE129_STATE                               0x407C // Unused Var
#define VAR_ROUTE130_STATE                               0x407D // Unused Var
#define VAR_ROUTE131_STATE                               0x407E // Unused Var
#define VAR_ROUTE132_STATE                               0x407F // Unused Var
#define VAR_ROUTE133_STATE                               0x4080 // Unused Var
#define VAR_ROUTE134_STATE                               0x4081 // Unused Var
#define VAR_LITTLEROOT_HOUSES_STATE_MAY                  0x4082
#define VAR_SANDGEM_TOWN_STATE                           0x4083
// @states Sandgem arrival, from meeting Lucas/Dawn to entering the lab.
//    0  Player has arrived in Sandgem
//    3  Lucas/Dawn has escorted player into the lab
//    6  Player has received Pokedex from Rowan
//    9  Lucas/Dawn has given Sandgem Town tour and told Player to go home. 
//   12  Lucas/Dawn has taught the player to catch/given them 10 Pokéballs
#define VAR_BIRCH_LAB_STATE                              0x4084
#define VAR_PETALBURG_GYM_STATE                          0x4085 // 0-1: Wally tutorial, 2-6: 0-4 badges, 7: Defeated Norman, 8: Rematch Norman
#define VAR_CONTEST_HALL_STATE                           0x4086
#define VAR_CABLE_CLUB_STATE                             0x4087
#define VAR_CONTEST_TYPE                                 0x4088
#define VAR_SECRET_BASE_INITIALIZED                      0x4089
#define VAR_CONTEST_PRIZE_PICKUP                         0x408A
#define VAR_JUBILIFE_CITY_STATE                          0x408B
// @states Jubilife story beats.
//    0  Player has just arrived to Jubilife
//    1  Lucas/Dawn points player to the Trainer School to meet Barry
//    2  Player has received Town Map from delivering Parcel to Barry
//    3  Player has received DexNav from the DexNavPresident, allowing them to leave Jubilife
//    4  Player has defeated Barry on Route 203
//    5  Player has defeated Roark and is returning to Jubilife
//    6  TODO
#define VAR_LITTLEROOT_HOUSES_STATE_BRENDAN              0x408C
#define VAR_LITTLEROOT_RIVAL_STATE                       0x408D
#define VAR_BOARD_BRINEY_BOAT_STATE                      0x408E
#define VAR_DEVON_CORP_3F_STATE                          0x408F
#define VAR_BRINEY_HOUSE_STATE                           0x4090
#define VAR_DEXNAV_SPECIES                               0x4091
#define VAR_LITTLEROOT_INTRO_STATE                       0x4092
#define VAR_MAUVILLE_GYM_STATE                           0x4093
#define VAR_LILYCOVE_MUSEUM_2F_STATE                     0x4094
#define VAR_LILYCOVE_FAN_CLUB_STATE                      0x4095
#define VAR_BRINEY_LOCATION                              0x4096
#define VAR_INIT_SECRET_BASE                             0x4097
#define VAR_PETALBURG_WOODS_STATE                        0x4098
#define VAR_LILYCOVE_CONTEST_LOBBY_STATE                 0x4099
#define VAR_RUSTURF_TUNNEL_STATE                         0x409A
#define VAR_DEXNAV_STEP_COUNTER                          0x409B
#define VAR_ELITE_4_STATE                                0x409C
#define VAR_OREBURGH_CITY_STATE                          0x409D
// @states Oreburgh Gym arc, from arriving to beating Roark.
//    0  Player has just arrived in Oreburgh
//    1  Player has talked to Barry blocking the Gym
//    2  Roark has demonstrated rock smash to the player and returns to the gym
//    3  Player has defeated Roark
//    4  Player has bumped into Barry while leaving Oreburgh City
#define VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE      0x409E
#define VAR_MOSSDEEP_SPACE_CENTER_STATE                  0x409F
#define VAR_SLATEPORT_HARBOR_STATE                       0x40A0
#define VAR_UNUSED_0x40A1                                0x40A1 // Unused var
#define VAR_SEAFLOOR_CAVERN_STATE                        0x40A2
#define VAR_CABLE_CAR_STATION_STATE                      0x40A3
#define VAR_SAFARI_ZONE_STATE                            0x40A4  // 0: In or out of SZ, 1: Player exiting SZ, 2: Player entering SZ
#define VAR_TRICK_HOUSE_BEING_WATCHED_STATE              0x40A5
#define VAR_TRICK_HOUSE_FOUND_TRICK_MASTER               0x40A6
#define VAR_TRICK_HOUSE_ENTRANCE_STATE                   0x40A7
#define VAR_UNUSED_0x40A8                                0x40A8 // Unused Var
#define VAR_CYCLING_CHALLENGE_STATE                      0x40A9
#define VAR_SLATEPORT_MUSEUM_1F_STATE                    0x40AA
#define VAR_TRICK_HOUSE_PUZZLE_1_STATE                   0x40AB
#define VAR_TRICK_HOUSE_PUZZLE_2_STATE                   0x40AC
#define VAR_TRICK_HOUSE_PUZZLE_3_STATE                   0x40AD
#define VAR_TRICK_HOUSE_PUZZLE_4_STATE                   0x40AE
#define VAR_TRICK_HOUSE_PUZZLE_5_STATE                   0x40AF
#define VAR_TRICK_HOUSE_PUZZLE_6_STATE                   0x40B0
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE                   0x40B1
#define VAR_TRICK_HOUSE_PUZZLE_8_STATE                   0x40B2
#define VAR_WEATHER_INSTITUTE_STATE                      0x40B3
#define VAR_SS_TIDAL_STATE                               0x40B4
#define VAR_TRICK_HOUSE_ENTER_FROM_CORRIDOR              0x40B5
#define VAR_TRICK_HOUSE_PUZZLE_7_STATE_2                 0x40B6 // Leftover from RS, never set
#define VAR_SLATEPORT_FAN_CLUB_STATE                     0x40B7
#define VAR_UNUSED_0x40B8                                0x40B8 // Unused Var
#define VAR_MT_PYRE_STATE                                0x40B9
#define VAR_NEW_MAUVILLE_STATE                           0x40BA
#define VAR_UNUSED_0x40BB                                0x40BB // Unused Var
#define VAR_BRAVO_TRAINER_BATTLE_TOWER_ON                0x40BC
#define VAR_JAGGED_PASS_ASH_WEATHER                      0x40BD
#define VAR_GLASS_WORKSHOP_STATE                         0x40BE
#define VAR_METEOR_FALLS_STATE                           0x40BF
#define VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE              0x40C0
#define VAR_TRICK_HOUSE_PRIZE_PICKUP                     0x40C1
#define VAR_PACIFIDLOG_TM_RECEIVED_DAY                   0x40C2
#define VAR_VICTORY_ROAD_1F_STATE                        0x40C3
#define VAR_FOSSIL_RESURRECTION_STATE                    0x40C4
#define VAR_WHICH_FOSSIL_REVIVED                         0x40C5
#define VAR_STEVENS_HOUSE_STATE                          0x40C6
#define VAR_OLDALE_RIVAL_STATE                           0x40C7
#define VAR_JAGGED_PASS_STATE                            0x40C8
#define VAR_SCOTT_PETALBURG_ENCOUNTER                    0x40C9
#define VAR_SKY_PILLAR_STATE                             0x40CA
#define VAR_MIRAGE_TOWER_STATE                           0x40CB
#define VAR_FOSSIL_MANIAC_STATE                          0x40CC
#define VAR_CABLE_CLUB_TUTORIAL_STATE                    0x40CD
#define VAR_FRONTIER_BATTLE_MODE                         0x40CE
#define VAR_FRONTIER_FACILITY                            0x40CF
#define VAR_HAS_ENTERED_BATTLE_FRONTIER                  0x40D0 // Var is used like a flag.
#define VAR_SCOTT_STATE                                  0x40D1
#define VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE               0x40D2
#define VAR_DEX_UPGRADE_JOHTO_STARTER_STATE              0x40D3
#define VAR_SS_TIDAL_SCOTT_STATE                         0x40D4 // Always equal to FLAG_MET_SCOTT_ON_SS_TIDAL
#define VAR_ROAMER_POKEMON                               0x40D5 // 0 = Latias, 1 = Latios
#define VAR_TRAINER_HILL_IS_ACTIVE                       0x40D6
#define VAR_SKY_PILLAR_RAYQUAZA_CRY_DONE                 0x40D7
#define VAR_SOOTOPOLIS_WALLACE_STATE                     0x40D8
#define VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT 0x40D9
#define VAR_REGISTER_BIRCH_STATE                         0x40DA
#define VAR_UNUSED_0x40DB                                0x40DB // Unused Var
#define VAR_UNUSED_0x40DC                                0x40DC // Unused Var
#define VAR_GIFT_PICHU_SLOT                              0x40DD
#define VAR_GIFT_UNUSED_1                                0x40DE // Var is written to, but never read
#define VAR_GIFT_UNUSED_2                                0x40DF // Var is written to, but never read
#define VAR_GIFT_UNUSED_3                                0x40E0 // Var is written to, but never read
#define VAR_GIFT_UNUSED_4                                0x40E1 // Var is written to, but never read
#define VAR_GIFT_UNUSED_5                                0x40E2 // Var is written to, but never read
#define VAR_GIFT_UNUSED_6                                0x40E3 // Var is written to, but never read
#define VAR_GIFT_UNUSED_7                                0x40E4 // var is written to, but never read
#define VAR_UNUSED_0x40E5                                0x40E5 // Unused Var
#define VAR_DAILY_SLOTS                                  0x40E6
#define VAR_DAILY_WILDS                                  0x40E7
#define VAR_DAILY_BLENDER                                0x40E8
#define VAR_DAILY_PLANTED_BERRIES                        0x40E9
#define VAR_DAILY_PICKED_BERRIES                         0x40EA
#define VAR_DAILY_ROULETTE                               0x40EB
#define VAR_SECRET_BASE_STEP_COUNTER                     0x40EC // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LAST_ITEM_USED                   0x40ED // Used by Secret Base TV programs
#define VAR_SECRET_BASE_LOW_TV_FLAGS                     0x40EE // Used by Secret Base TV programs
#define VAR_SECRET_BASE_HIGH_TV_FLAGS                    0x40EF // Used by Secret Base TV programs
#define VAR_SECRET_BASE_IS_NOT_LOCAL                     0x40F0 // Set to TRUE while in another player's secret base.
#define VAR_DAILY_BP                                     0x40F1
#define VAR_WALLY_CALL_STEP_COUNTER                      0x40F2
#define VAR_SCOTT_FORTREE_CALL_STEP_COUNTER              0x40F3
#define VAR_ROXANNE_CALL_STEP_COUNTER                    0x40F4
#define VAR_SCOTT_BF_CALL_STEP_COUNTER                   0x40F5
#define VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER             0x40F6
#define VAR_UNUSED_0x40F7                                0x40F7 // Unused Var
#define VAR_UNUSED_0x40F8                                0x40F8 // Unused Var
#define VAR_UNUSED_0x40F9                                0x40F9 // Unused Var
#define VAR_UNUSED_0x40FA                                0x40FA // Unused Var
#define VAR_UNUSED_0x40FB                                0x40FB // Unused Var
#define VAR_UNUSED_0x40FC                                0x40FC // Unused Var
#define VAR_UNUSED_0x40FD                                0x40FD // Unused Var
#define VAR_UNUSED_0x40FE                                0x40FE // Unused Var
#define VAR_UNUSED_0x40FF                                0x40FF // Unused Var

#define VARS_END                                         0x40FF
#define VARS_COUNT                                       (VARS_END - VARS_START + 1)

// Extra vars for Sinnoh content, stored in SaveBlock1.varsExtra (appended so older saves still load).
// 0x7000+ so they can't collide with literal values like OBJ_EVENT_GFX_SPECIES (0x4000 + species).
#define EXTRA_VARS_START                                 0x7000
#define VAR_ROUTE205_STATE                               0x7000
// @states Imported from Diamond/Pearl (DP var 0x4089).
//    0  TODO
//    1  TODO
#define VAR_FLOAROMA_TOWN_STATE                          0x7001
// @states Imported from Diamond/Pearl (DP var 0x4072).
//    0  TODO
//    1  TODO
#define VAR_FLOAROMA_MEADOW_STATE                        0x7002
// @states Imported from Diamond/Pearl (DP var 0x40E9).
//    0  TODO
//    1  TODO
#define VAR_VALLEY_WINDWORKS_STATE                       0x7003
// @states Imported from Diamond/Pearl (DP var 0x40CF).
//    0  TODO
//    2  TODO
//    3  TODO
#define VAR_ETERNA_FOREST_STATE                          0x7004
// @states Imported from Diamond/Pearl (DP var 0x40B1).
//    0  TODO
//    1  TODO
//    2  TODO
#define VAR_ETERNA_FOREST_STATE_2                        0x7005
// @states Imported from Diamond/Pearl (DP var 0x403F).
//    0  TODO
//    608  TODO
#define VAR_OLD_CHATEAU_1F_STATE                         0x7006
// @states Imported from Diamond/Pearl (DP var 0x4110).
//    0  TODO
//    1  TODO
#define VAR_ETERNA_CITY_STATE                            0x7007
// @states Imported from Diamond/Pearl (DP var 0x407A).
//    0  TODO
//    1  TODO
#define VAR_ETERNA_CITY_STATE_2                          0x7008
// @states Imported from Diamond/Pearl (DP var 0x4114).
//    0  TODO
//    1  TODO
#define VAR_ETERNA_CITY_STATE_3                          0x7009
// @states Imported from Diamond/Pearl (DP var 0x411B).
//    0  TODO
//    1  TODO
#define VAR_CANALAVE_CITY_STATE                          0x700A
// @states Imported from Diamond/Pearl (DP var 0x4106).
//    0  TODO
//    2  TODO
#define VAR_CANALAVE_CITY_STATE_2                        0x700B
// @states Imported from Diamond/Pearl (DP var 0x4078).
//    0  TODO
//    1  TODO
//    2  TODO
//    3  TODO
//    4  TODO
//    5  TODO
//    6  TODO
#define VAR_CANALAVE_CITY_STATE_3                        0x700C
// @states Imported from Diamond/Pearl (DP var 0x40F8).
//    0  TODO
//    2  TODO
//    3  TODO
//    4  TODO
#define VAR_CANALAVE_CITY_STATE_4                        0x700D
// @states Imported from Diamond/Pearl (DP var 0x4020).
//    0  TODO
//    97  TODO
#define VAR_CANALAVE_CITY_STATE_5                        0x700E
// @states Imported from Diamond/Pearl (DP var 0x40B2).
//    0  TODO
//    1  TODO
#define VAR_OREBURGH_GATE_STATE                          0x700F
// @states Imported from Diamond/Pearl (DP var 0x4093).
//    0  TODO
//    1  TODO
//    2  TODO
#define VAR_JUBILIFE_CITY_TVSTATION_1F_STATE             0x7010
// @states Imported from Diamond/Pearl (DP var 0x40F2).
//    0  TODO
#define VAR_JUBILIFE_CITY_TVSTATION_2F_STATE             0x7011
// @states Imported from Diamond/Pearl (DP var 0x410A).
//    0  TODO
#define VAR_ETERNA_CITY_GYM_STATE                        0x7012
// @states Imported from Diamond/Pearl (DP var 0x40AE).
//    0  TODO
//    1  TODO
//    2  TODO
//    3  TODO
//    4  TODO
#define VAR_ROUTE206_ETERNA_GATEHOUSE_STATE              0x7013
// @states Imported from Diamond/Pearl (DP var 0x40EC).
//    0  TODO
#define VAR_ROUTE218_CANALAVE_GATEHOUSE_STATE            0x7014
// @states Imported from Diamond/Pearl (DP var 0x4105).
//    0  TODO
//    1  TODO
#define VAR_ROUTE206_STATE                               0x7015
// @states Imported from Diamond/Pearl (DP var 0x411C).
//    0  TODO
//    1  TODO
#define VAR_WAYWARD_CAVE_1F_STATE                        0x7016
// @states Imported from Diamond/Pearl (DP var 0x4091).
//    0  TODO
//    1  TODO
//    2  TODO
#define VAR_WAYWARD_CAVE_1F_STATE_2                      0x7017
// @states Imported from Diamond/Pearl (DP var 0x40E2).
//    0  TODO
//    1  TODO
//    2  TODO
#define VAR_UNUSED_0x7018                        0x7018 // Unused Var
#define VAR_UNUSED_0x7019                        0x7019 // Unused Var
#define VAR_UNUSED_0x701A                        0x701A // Unused Var
#define VAR_UNUSED_0x701B                        0x701B // Unused Var
#define VAR_UNUSED_0x701C                        0x701C // Unused Var
#define VAR_UNUSED_0x701D                        0x701D // Unused Var
#define VAR_UNUSED_0x701E                        0x701E // Unused Var
#define VAR_UNUSED_0x701F                        0x701F // Unused Var
#define VAR_UNUSED_0x7020                        0x7020 // Unused Var
#define VAR_UNUSED_0x7021                        0x7021 // Unused Var
#define VAR_UNUSED_0x7022                        0x7022 // Unused Var
#define VAR_UNUSED_0x7023                        0x7023 // Unused Var
#define VAR_UNUSED_0x7024                        0x7024 // Unused Var
#define VAR_UNUSED_0x7025                        0x7025 // Unused Var
#define VAR_UNUSED_0x7026                        0x7026 // Unused Var
#define VAR_UNUSED_0x7027                        0x7027 // Unused Var
#define VAR_UNUSED_0x7028                        0x7028 // Unused Var
#define VAR_UNUSED_0x7029                        0x7029 // Unused Var
#define VAR_UNUSED_0x702A                        0x702A // Unused Var
#define VAR_UNUSED_0x702B                        0x702B // Unused Var
#define VAR_UNUSED_0x702C                        0x702C // Unused Var
#define VAR_UNUSED_0x702D                        0x702D // Unused Var
#define VAR_UNUSED_0x702E                        0x702E // Unused Var
#define VAR_UNUSED_0x702F                        0x702F // Unused Var
#define VAR_UNUSED_0x7030                        0x7030 // Unused Var
#define VAR_UNUSED_0x7031                        0x7031 // Unused Var
#define VAR_UNUSED_0x7032                        0x7032 // Unused Var
#define VAR_UNUSED_0x7033                        0x7033 // Unused Var
#define VAR_UNUSED_0x7034                        0x7034 // Unused Var
#define VAR_UNUSED_0x7035                        0x7035 // Unused Var
#define VAR_UNUSED_0x7036                        0x7036 // Unused Var
#define VAR_UNUSED_0x7037                        0x7037 // Unused Var
#define VAR_UNUSED_0x7038                        0x7038 // Unused Var
#define VAR_UNUSED_0x7039                        0x7039 // Unused Var
#define VAR_UNUSED_0x703A                        0x703A // Unused Var
#define VAR_UNUSED_0x703B                        0x703B // Unused Var
#define VAR_UNUSED_0x703C                        0x703C // Unused Var
#define VAR_UNUSED_0x703D                        0x703D // Unused Var
#define VAR_UNUSED_0x703E                        0x703E // Unused Var
#define VAR_UNUSED_0x703F                        0x703F // Unused Var
#define VAR_UNUSED_0x7040                        0x7040 // Unused Var
#define VAR_UNUSED_0x7041                        0x7041 // Unused Var
#define VAR_UNUSED_0x7042                        0x7042 // Unused Var
#define VAR_UNUSED_0x7043                        0x7043 // Unused Var
#define VAR_UNUSED_0x7044                        0x7044 // Unused Var
#define VAR_UNUSED_0x7045                        0x7045 // Unused Var
#define VAR_UNUSED_0x7046                        0x7046 // Unused Var
#define VAR_UNUSED_0x7047                        0x7047 // Unused Var
#define VAR_UNUSED_0x7048                        0x7048 // Unused Var
#define VAR_UNUSED_0x7049                        0x7049 // Unused Var
#define VAR_UNUSED_0x704A                        0x704A // Unused Var
#define VAR_UNUSED_0x704B                        0x704B // Unused Var
#define VAR_UNUSED_0x704C                        0x704C // Unused Var
#define VAR_UNUSED_0x704D                        0x704D // Unused Var
#define VAR_UNUSED_0x704E                        0x704E // Unused Var
#define VAR_UNUSED_0x704F                        0x704F // Unused Var
#define VAR_UNUSED_0x7050                        0x7050 // Unused Var
#define VAR_UNUSED_0x7051                        0x7051 // Unused Var
#define VAR_UNUSED_0x7052                        0x7052 // Unused Var
#define VAR_UNUSED_0x7053                        0x7053 // Unused Var
#define VAR_UNUSED_0x7054                        0x7054 // Unused Var
#define VAR_UNUSED_0x7055                        0x7055 // Unused Var
#define VAR_UNUSED_0x7056                        0x7056 // Unused Var
#define VAR_UNUSED_0x7057                        0x7057 // Unused Var
#define VAR_UNUSED_0x7058                        0x7058 // Unused Var
#define VAR_UNUSED_0x7059                        0x7059 // Unused Var
#define VAR_UNUSED_0x705A                        0x705A // Unused Var
#define VAR_UNUSED_0x705B                        0x705B // Unused Var
#define VAR_UNUSED_0x705C                        0x705C // Unused Var
#define VAR_UNUSED_0x705D                        0x705D // Unused Var
#define VAR_UNUSED_0x705E                        0x705E // Unused Var
#define VAR_UNUSED_0x705F                        0x705F // Unused Var
#define VAR_UNUSED_0x7060                        0x7060 // Unused Var
#define VAR_UNUSED_0x7061                        0x7061 // Unused Var
#define VAR_UNUSED_0x7062                        0x7062 // Unused Var
#define VAR_UNUSED_0x7063                        0x7063 // Unused Var
#define VAR_UNUSED_0x7064                        0x7064 // Unused Var
#define VAR_UNUSED_0x7065                        0x7065 // Unused Var
#define VAR_UNUSED_0x7066                        0x7066 // Unused Var
#define VAR_UNUSED_0x7067                        0x7067 // Unused Var
#define VAR_UNUSED_0x7068                        0x7068 // Unused Var
#define VAR_UNUSED_0x7069                        0x7069 // Unused Var
#define VAR_UNUSED_0x706A                        0x706A // Unused Var
#define VAR_UNUSED_0x706B                        0x706B // Unused Var
#define VAR_UNUSED_0x706C                        0x706C // Unused Var
#define VAR_UNUSED_0x706D                        0x706D // Unused Var
#define VAR_UNUSED_0x706E                        0x706E // Unused Var
#define VAR_UNUSED_0x706F                        0x706F // Unused Var
#define VAR_UNUSED_0x7070                        0x7070 // Unused Var
#define VAR_UNUSED_0x7071                        0x7071 // Unused Var
#define VAR_UNUSED_0x7072                        0x7072 // Unused Var
#define VAR_UNUSED_0x7073                        0x7073 // Unused Var
#define VAR_UNUSED_0x7074                        0x7074 // Unused Var
#define VAR_UNUSED_0x7075                        0x7075 // Unused Var
#define VAR_UNUSED_0x7076                        0x7076 // Unused Var
#define VAR_UNUSED_0x7077                        0x7077 // Unused Var
#define VAR_UNUSED_0x7078                        0x7078 // Unused Var
#define VAR_UNUSED_0x7079                        0x7079 // Unused Var
#define VAR_UNUSED_0x707A                        0x707A // Unused Var
#define VAR_UNUSED_0x707B                        0x707B // Unused Var
#define VAR_UNUSED_0x707C                        0x707C // Unused Var
#define VAR_UNUSED_0x707D                        0x707D // Unused Var
#define VAR_UNUSED_0x707E                        0x707E // Unused Var
#define VAR_UNUSED_0x707F                        0x707F // Unused Var
#define VAR_UNUSED_0x7080                        0x7080 // Unused Var
#define VAR_UNUSED_0x7081                        0x7081 // Unused Var
#define VAR_UNUSED_0x7082                        0x7082 // Unused Var
#define VAR_UNUSED_0x7083                        0x7083 // Unused Var
#define VAR_UNUSED_0x7084                        0x7084 // Unused Var
#define VAR_UNUSED_0x7085                        0x7085 // Unused Var
#define VAR_UNUSED_0x7086                        0x7086 // Unused Var
#define VAR_UNUSED_0x7087                        0x7087 // Unused Var
#define VAR_UNUSED_0x7088                        0x7088 // Unused Var
#define VAR_UNUSED_0x7089                        0x7089 // Unused Var
#define VAR_UNUSED_0x708A                        0x708A // Unused Var
#define VAR_UNUSED_0x708B                        0x708B // Unused Var
#define VAR_UNUSED_0x708C                        0x708C // Unused Var
#define VAR_UNUSED_0x708D                        0x708D // Unused Var
#define VAR_UNUSED_0x708E                        0x708E // Unused Var
#define VAR_UNUSED_0x708F                        0x708F // Unused Var
#define VAR_UNUSED_0x7090                        0x7090 // Unused Var
#define VAR_UNUSED_0x7091                        0x7091 // Unused Var
#define VAR_UNUSED_0x7092                        0x7092 // Unused Var
#define VAR_UNUSED_0x7093                        0x7093 // Unused Var
#define VAR_UNUSED_0x7094                        0x7094 // Unused Var
#define VAR_UNUSED_0x7095                        0x7095 // Unused Var
#define VAR_UNUSED_0x7096                        0x7096 // Unused Var
#define VAR_UNUSED_0x7097                        0x7097 // Unused Var
#define VAR_UNUSED_0x7098                        0x7098 // Unused Var
#define VAR_UNUSED_0x7099                        0x7099 // Unused Var
#define VAR_UNUSED_0x709A                        0x709A // Unused Var
#define VAR_UNUSED_0x709B                        0x709B // Unused Var
#define VAR_UNUSED_0x709C                        0x709C // Unused Var
#define VAR_UNUSED_0x709D                        0x709D // Unused Var
#define VAR_UNUSED_0x709E                        0x709E // Unused Var
#define VAR_UNUSED_0x709F                        0x709F // Unused Var
#define VAR_UNUSED_0x70A0                        0x70A0 // Unused Var
#define VAR_UNUSED_0x70A1                        0x70A1 // Unused Var
#define VAR_UNUSED_0x70A2                        0x70A2 // Unused Var
#define VAR_UNUSED_0x70A3                        0x70A3 // Unused Var
#define VAR_UNUSED_0x70A4                        0x70A4 // Unused Var
#define VAR_UNUSED_0x70A5                        0x70A5 // Unused Var
#define VAR_UNUSED_0x70A6                        0x70A6 // Unused Var
#define VAR_UNUSED_0x70A7                        0x70A7 // Unused Var
#define VAR_UNUSED_0x70A8                        0x70A8 // Unused Var
#define VAR_UNUSED_0x70A9                        0x70A9 // Unused Var
#define VAR_UNUSED_0x70AA                        0x70AA // Unused Var
#define VAR_UNUSED_0x70AB                        0x70AB // Unused Var
#define VAR_UNUSED_0x70AC                        0x70AC // Unused Var
#define VAR_UNUSED_0x70AD                        0x70AD // Unused Var
#define VAR_UNUSED_0x70AE                        0x70AE // Unused Var
#define VAR_UNUSED_0x70AF                        0x70AF // Unused Var
#define VAR_UNUSED_0x70B0                        0x70B0 // Unused Var
#define VAR_UNUSED_0x70B1                        0x70B1 // Unused Var
#define VAR_UNUSED_0x70B2                        0x70B2 // Unused Var
#define VAR_UNUSED_0x70B3                        0x70B3 // Unused Var
#define VAR_UNUSED_0x70B4                        0x70B4 // Unused Var
#define VAR_UNUSED_0x70B5                        0x70B5 // Unused Var
#define VAR_UNUSED_0x70B6                        0x70B6 // Unused Var
#define VAR_UNUSED_0x70B7                        0x70B7 // Unused Var
#define VAR_UNUSED_0x70B8                        0x70B8 // Unused Var
#define VAR_UNUSED_0x70B9                        0x70B9 // Unused Var
#define VAR_UNUSED_0x70BA                        0x70BA // Unused Var
#define VAR_UNUSED_0x70BB                        0x70BB // Unused Var
#define VAR_UNUSED_0x70BC                        0x70BC // Unused Var
#define VAR_UNUSED_0x70BD                        0x70BD // Unused Var
#define VAR_UNUSED_0x70BE                        0x70BE // Unused Var
#define VAR_UNUSED_0x70BF                        0x70BF // Unused Var
#define VAR_UNUSED_0x70C0                        0x70C0 // Unused Var
#define VAR_UNUSED_0x70C1                        0x70C1 // Unused Var
#define VAR_UNUSED_0x70C2                        0x70C2 // Unused Var
#define VAR_UNUSED_0x70C3                        0x70C3 // Unused Var
#define VAR_UNUSED_0x70C4                        0x70C4 // Unused Var
#define VAR_UNUSED_0x70C5                        0x70C5 // Unused Var
#define VAR_UNUSED_0x70C6                        0x70C6 // Unused Var
#define VAR_UNUSED_0x70C7                        0x70C7 // Unused Var
#define VAR_UNUSED_0x70C8                        0x70C8 // Unused Var
#define VAR_UNUSED_0x70C9                        0x70C9 // Unused Var
#define VAR_UNUSED_0x70CA                        0x70CA // Unused Var
#define VAR_UNUSED_0x70CB                        0x70CB // Unused Var
#define VAR_UNUSED_0x70CC                        0x70CC // Unused Var
#define VAR_UNUSED_0x70CD                        0x70CD // Unused Var
#define VAR_UNUSED_0x70CE                        0x70CE // Unused Var
#define VAR_UNUSED_0x70CF                        0x70CF // Unused Var
#define VAR_UNUSED_0x70D0                        0x70D0 // Unused Var
#define VAR_UNUSED_0x70D1                        0x70D1 // Unused Var
#define VAR_UNUSED_0x70D2                        0x70D2 // Unused Var
#define VAR_UNUSED_0x70D3                        0x70D3 // Unused Var
#define VAR_UNUSED_0x70D4                        0x70D4 // Unused Var
#define VAR_UNUSED_0x70D5                        0x70D5 // Unused Var
#define VAR_UNUSED_0x70D6                        0x70D6 // Unused Var
#define VAR_UNUSED_0x70D7                        0x70D7 // Unused Var
#define VAR_UNUSED_0x70D8                        0x70D8 // Unused Var
#define VAR_UNUSED_0x70D9                        0x70D9 // Unused Var
#define VAR_UNUSED_0x70DA                        0x70DA // Unused Var
#define VAR_UNUSED_0x70DB                        0x70DB // Unused Var
#define VAR_UNUSED_0x70DC                        0x70DC // Unused Var
#define VAR_UNUSED_0x70DD                        0x70DD // Unused Var
#define VAR_UNUSED_0x70DE                        0x70DE // Unused Var
#define VAR_UNUSED_0x70DF                        0x70DF // Unused Var
#define VAR_UNUSED_0x70E0                        0x70E0 // Unused Var
#define VAR_UNUSED_0x70E1                        0x70E1 // Unused Var
#define VAR_UNUSED_0x70E2                        0x70E2 // Unused Var
#define VAR_UNUSED_0x70E3                        0x70E3 // Unused Var
#define VAR_UNUSED_0x70E4                        0x70E4 // Unused Var
#define VAR_UNUSED_0x70E5                        0x70E5 // Unused Var
#define VAR_UNUSED_0x70E6                        0x70E6 // Unused Var
#define VAR_UNUSED_0x70E7                        0x70E7 // Unused Var
#define VAR_UNUSED_0x70E8                        0x70E8 // Unused Var
#define VAR_UNUSED_0x70E9                        0x70E9 // Unused Var
#define VAR_UNUSED_0x70EA                        0x70EA // Unused Var
#define VAR_UNUSED_0x70EB                        0x70EB // Unused Var
#define VAR_UNUSED_0x70EC                        0x70EC // Unused Var
#define VAR_UNUSED_0x70ED                        0x70ED // Unused Var
#define VAR_UNUSED_0x70EE                        0x70EE // Unused Var
#define VAR_UNUSED_0x70EF                        0x70EF // Unused Var
#define VAR_UNUSED_0x70F0                        0x70F0 // Unused Var
#define VAR_UNUSED_0x70F1                        0x70F1 // Unused Var
#define VAR_UNUSED_0x70F2                        0x70F2 // Unused Var
#define VAR_UNUSED_0x70F3                        0x70F3 // Unused Var
#define VAR_UNUSED_0x70F4                        0x70F4 // Unused Var
#define VAR_UNUSED_0x70F5                        0x70F5 // Unused Var
#define VAR_UNUSED_0x70F6                        0x70F6 // Unused Var
#define VAR_UNUSED_0x70F7                        0x70F7 // Unused Var
#define VAR_UNUSED_0x70F8                        0x70F8 // Unused Var
#define VAR_UNUSED_0x70F9                        0x70F9 // Unused Var
#define VAR_UNUSED_0x70FA                        0x70FA // Unused Var
#define VAR_UNUSED_0x70FB                        0x70FB // Unused Var
#define VAR_UNUSED_0x70FC                        0x70FC // Unused Var
#define VAR_UNUSED_0x70FD                        0x70FD // Unused Var
#define VAR_UNUSED_0x70FE                        0x70FE // Unused Var
#define VAR_UNUSED_0x70FF                        0x70FF // Unused Var
#define EXTRA_VARS_END                                   0x70FF
#define NUM_EXTRA_VARS                                   (EXTRA_VARS_END - EXTRA_VARS_START + 1)

#define SPECIAL_VARS_START            0x8000
// special vars
// They are commonly used as parameters to commands, or return values from commands.
#define VAR_0x8000                    0x8000
#define VAR_0x8001                    0x8001
#define VAR_0x8002                    0x8002
#define VAR_0x8003                    0x8003
#define VAR_0x8004                    0x8004
#define VAR_0x8005                    0x8005
#define VAR_0x8006                    0x8006
#define VAR_0x8007                    0x8007
#define VAR_0x8008                    0x8008
#define VAR_0x8009                    0x8009
#define VAR_0x800A                    0x800A
#define VAR_0x800B                    0x800B
#define VAR_FACING                    0x800C
#define VAR_RESULT                    0x800D
#define VAR_ITEM_ID                   0x800E
#define VAR_LAST_TALKED               0x800F
#define VAR_CONTEST_RANK              0x8010
#define VAR_CONTEST_CATEGORY          0x8011
#define VAR_MON_BOX_ID                0x8012
#define VAR_MON_BOX_POS               0x8013
#define VAR_UNUSED_0x8014             0x8014
#define VAR_TRAINER_BATTLE_OPPONENT_A 0x8015 // Alias of TRAINER_BATTLE_PARAM.opponentA

#define SPECIAL_VARS_END              0x8015

// If an overworld trigger uses this pseudo-variable as the trigger check,
// then the script will be run using RunScriptImmediately instead of in the
// global script context. This means it will run faster, but cannot do any
// cutscenes nor call a wait command. Used for weather effects in vanilla.
#define TRIGGER_RUN_IMMEDIATELY   0

// Temp var aliases
#define VAR_TEMP_CHALLENGE_STATUS  VAR_TEMP_0

#define VAR_TEMP_MIXED_RECORDS         VAR_TEMP_0
#define VAR_TEMP_RECORD_MIX_GIFT_ITEM  VAR_TEMP_1

#define VAR_TEMP_PLAYING_PYRAMID_MUSIC  VAR_TEMP_E

#define VAR_TEMP_FRONTIER_TUTOR_SELECTION  VAR_TEMP_D
#define VAR_TEMP_FRONTIER_TUTOR_ID         VAR_TEMP_E

#define VAR_TEMP_TRANSFERRED_SPECIES  VAR_TEMP_1

#if TESTING
#define TESTING_VARS_START                  0x9000
#define TESTING_VAR_DIFFICULTY              (TESTING_VARS_START + 0x0)
#define TESTING_VAR_TRAINER_SLIDES          (TESTING_VARS_START + 0x1)
#define TESTING_VAR_UNUSED_2                (TESTING_VARS_START + 0x2)
#define TESTING_VAR_UNUSED_3                (TESTING_VARS_START + 0x3)
#define TESTING_VAR_UNUSED_4                (TESTING_VARS_START + 0x4)
#define TESTING_VAR_UNUSED_5                (TESTING_VARS_START + 0x5)
#define TESTING_VAR_UNUSED_6                (TESTING_VARS_START + 0x6)
#define TESTING_VAR_UNUSED_7                (TESTING_VARS_START + 0x7)
#endif // TESTING

#endif // GUARD_CONSTANTS_VARS_H
