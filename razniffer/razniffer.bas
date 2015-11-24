; Razbit's bus sniffer - rzniffer
; Copyright Eetu "Razbit" Pesonen, 2014

symbol nibble = b7
symbol SNIB = C.2
symbol nLBYTE = C.0
symbol nHBYTE = C.1

main:	
	setfreq m64
	dirsB = 0xFF
	dirsC = 0x0F
	
	nibble = 0 ; index of the nibble (out of 4) we are reading
	
	; default to lower nibble of lower byte
	low SNIB
	low nLBYTE
	high nHBYTE
	
	goto looper
	
looper:

	; mux controlling to get the right input
	if nibble = 0 then
		low SNIB
		low nLBYTE
		high nHBYTE
	elseif nibble = 1 then
		high SNIB
		low nLBYTE
		high nHBYTE
	elseif nibble = 2 then
		low SNIB
		high nLBYTE
		low nHBYTE
	else
		high SNIB
		high nLBYTE
		low nHBYTE
	endif

	;b0 = 
	b2 = pinsC >> 4
	
	if b2 = 0 then
		let pinsB = %01000000
	elseif b2 = 1 then
		let pinsB = %01111001
	elseif b2 = 2 then
		let pinsB = %00100100 
	elseif b2 = 3 then
		let pinsB = %00110000 
	elseif b2 = 4 then
		let pinsB = %00011001 
	elseif b2 = 5 then
		let pinsB = %00010010
	elseif b2 = 6 then
		let pinsB = %00000010 
	elseif b2 = 7 then
		let pinsB = %01111000
	elseif b2 = 8 then
		let pinsB = %00000000
	elseif b2 = 9 then
		let pinsB = %00010000
	elseif b2 = 10 then
		let pinsB = %00001000 
	elseif b2 = 11 then
		let pinsB = %00000011 
	elseif b2 = 12 then
		let pinsB = %01000110
	elseif b2 = 13 then
		let pinsB = %00100001 
	elseif b2 = 14 then
		let pinsB = %00000110 
	else
		let pinsB = %00001110
	endif
	
	pause 25
	inc nibble
	
	if nibble = 4 then
		nibble = 0
	endif
	
	let pinsB = 0xFF ; clear
	
goto looper

DIG0:
	let pinsB = %01000000 
	return

DIG1:
	let pinsB = %01111001 
	return

DIG2:
	let pinsB = %00100100 
	return

DIG3:
	let pinsB = %00110000 
	return

DIG4:
	let pinsB = %00011001 
	return

DIG5:
	let pinsB = %00010010 
	return

DIG6:
	let pinsB = %00000010 
	return

DIG7:
	let pinsB = %01111000 
	return

DIG8:
	let pinsB = %00000000 
	return

DIG9:
	let pinsB = %00010000 
	return

DIGA:
	let pinsB = %00001000 
	return

DIGB:
	let pinsB = %00000011 
	return

DIGC:
	let pinsB = %01000110 
	return

DIGD:
	let pinsB = %00100001 
	return

DIGE:
	let pinsB = %00000110 
	return

DIGF:
	let pinsB = %00001110 
	return

	