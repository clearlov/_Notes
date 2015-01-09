/**
 *	sizeof(struct..)
		align to the largest number with sequence
		2 1 1 	= 4 = 2 [11]
		1 1 2 	= 4 = [11] 2
		1 2 1 	= 6 = [1@] 2 [1@]
		1 2 1 1 = 6 = [1@] 2 [11]
		1 4 1 2 = 12 = [1@@@] 4 [1@2]
		1 4 3 2 = 16 = [1@@@] 4 [3@] [2@@]
 */

struct Allergic{	// 32 = [4@@@@] 8 [1@24] [4@@@@]
	int wound;			// 0x7f..a0		4 bytes + 4
	const char* victim;	// 0x7f..a8		8 bytes --> largest number
	char respirate;		// 0x7f..b0		1 + 1
	short advantageous;	// 0x7f..b2
	int rodent;			// 0x7f..b4
	int sneezy;			// 0x7f..b8
};				
Allergic allergic = {4, "victimize", 'V', 400, 444};
struct Allergic allergic = {4, "victimize", 'V', 400, 444}; 	// C-Style

typedef struct {								// C-Style
	int vomit;
	const char* vomitus;
} Abnormality, *Seizure;

// abnormality = {4, "victimize"} 
Abnormality abnormality = allergic;	//Abnormality *abnormality = &allergic;
Seizure seizure = &allergic;  // Seizure *seizure = allergic;

typedef struct Avian{							// C-Style
	int subtle;
	const char* slight;
	char 
} Brutal;
struct Avian avian = allergic;
Brutal *avian = &allergic;



/**
 * Assign the packing alignment in Struct and Union
 *	#pragma pack([ BYTES ?=8 ]);
		[ BYTES ]: 2^0, 2^1, 2^2, ?=2^3, 2^4 ...
 */

#pragma pack(2)
struct Allergic{     // 22 = [1@][8][1@][2][4][4]
	int wound;
	const char* victim;
	char respirate;
	short advantageous;
	int rodent;
	int sneezy;
}
 
#pragma pack(4)
struct Allergic{	// 24 = [1@@@][8][1@2][4][4]
} 
 
 
 

/**
 * sizeof(union..)
		the largest number
 */
union Suppress{		// 32 bytes
	double lethe;		// 8 bytes
	Allergic allergic;	//32 bytes
	float faeces;		// 4 bytes
};

Suppress supress = {120.33};

typedef union{							// C-Style
	char c;			// 1 byte, and char is [-128, 127]
	int anarch;
	int bobby;
} Unionize;

Unionize u;
u.c = 0x0000007f;   //  127
cout << u.anarch;  //127
cout << u.boddy;  // 127

u.anarch = 383;  // 0x0000017f
int x = u.c;  // c is the last byte of the int(4 bytes) ==>7f
cout << x;  // 127

