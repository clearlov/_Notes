/**
 *	sizeof(struct..)
		align to the largest number with sequence
		2 1 1 	= 4 = 2 [11]
		1 1 2 	= 4 = [11] 2
		1 2 1 	= 6 = [10] 2 [10]
		1 2 1 1 = 6 = [10] 2 [11]
		1 4 1 2 = 12 = [1000] 4 [102]
		1 4 3 2 = 16 = [1000] 4 [30] [200]
 */

struct Allergic{	// 32 = [40000] 8 [10004] [40000]
	int wound;			// 0x7f..00		4 bytes + 4
	const char* victim;	// 0x7f..08		8 bytes --> largest number
	char respirate;		// 0x7f..10		1 bytes
	int rodent;			// 0x7f..14
	int sneezy;			// 0x7f..18
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

