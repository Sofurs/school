#pragma once

// length of numbers

#define MNUMLEN 13
#define LNUMLEN 10

// mobile dial codes
#define MDIALCODESVK "+421"

// line dial codes
#define LDIALCODEBA "02"   // telefonne pasmo Bratislava
#define LDIALCODEDS "031"  // telefonne pasmo Dunajska Streda
#define LDIALCODETR "032"  // telefonne pasmo Trencin
#define LDIALCODETT "033"  // telefonne pasmo Trnava
#define LDIALCODESC "034"  // telefonne pasmo Senica
#define LDIALCODENZ "035"  // telefonne pasmo Nove Zamky
#define LDIALCODELV "036"  // telefonne pasmo Levice
#define LDIALCODENI "037"  // telefonne pasmo Nitra
#define LDIALCODETP "038"  // telefonne pasmo Topolcianky
#define LDIALCODEZA "041"  // telefonne pasmo Zilina
#define LDIALCODEPB "042"  // telefonne pasmo Povazska Bystrica
#define LDIALCODEMT "043"  // telefonne pasmo Martin
#define LDIALCODELM "044"  // telefonne pasmo Liptovsky Mikulas
#define LDIALCODEZV "045"  // telefonne pasmo Zvolen
#define LDIALCODEPR "046"  // telefonne pasmo Prievidza
#define LDIALCODELC "047"  // telefonne pasmo Lucenec
#define LDIALCODEBB "048"  // telefonne pasmo Banska Bystrica
#define LDIALCODEPS "051"  // telefonne pasmo Presov
#define LDIALCODEPP "052"  // telefonne pasmo Poprad
#define LDIALCODESN "053"  // telefonne pasmo Spisska Nova Ves
#define LDIALCODEBR "054"  // telefonne pasmo Bardejov
#define LDIALCODEKK "055"  // telefonne pasmo Kosice
#define LDIALCODEMI "056"  // telefonne pasmo Michalovce
#define LDIALCODEHM "057"  // telefonne pasmo Humenne
#define LDIALCODERO "058"  // telefonne pasmo Roznava

// comparison functions

#define comp2(X) buffer.compare(0, 2, X)
#define comp3(X) buffer.compare(0, 3, X)