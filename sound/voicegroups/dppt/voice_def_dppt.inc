@ Trimmed from ipatix's VoiceDef.s (GBA-Pokemon-DPPt-Music) -- type constants only.
@ Note-name constants intentionally omitted: pastel-pearl's sound/MPlayDef.s already
@ defines the identical Cn3-style note table; voicegroup_dppt.inc uses raw numbers.

@***
@
@ VoiceDef.s V0.2
@ (C) 2014 ipatix
@                    
@**************************************************************@

@***
@ Output Device
@**********************@

	.equ	DirectSound, 	0x00
	.equ	SquareWave1,	0x01
	.equ	SquareWave2,	0x02
	.equ	ProgWave,	0x03
	.equ	ProgNoise,	0x04
	.equ	DirectSoundFix,	0x08
	.equ	DirectReverse,	0x10
	.equ	DirectComp,	0x20
	.equ	ReverseComp,	0x30

@***
@ Table Types
@**********************@

	.equ	KeySplit, 	0x40
	.equ	DrumTable,	0x80

@***
@ Wave Patterns
@**********************@

	.equ	WaveDuty75,	0x03
	.equ	WaveDuty50, 	0x02
	.equ	WaveDuty25,	0x01
	.equ	WaveDuty12,	0x00

	.equ	FineNoise,	0x00
	.equ	RoughNoise,	0x01

	.equ	c_v,	0x40		@ pan/bend baseline, matches sound/MPlayDef.s
