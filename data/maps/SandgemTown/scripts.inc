SandgemTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_OnTransition
	.byte 0

SandgemTown_OnTransition:
	setflag FLAG_VISITED_SANDGEM_TOWN
	end
