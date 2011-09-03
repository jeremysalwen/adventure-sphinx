/* This generated file is licenced and copyrighted under the same 
 * conditions as the sourcefile. Happy debugging:) */

/*
    defines:
*/

#define HOLD        unsigned hold___BNF_level = __BNF_level; char *hold___BNF_input = __BNF_input, *hold___BNF_output = __BNF_output
#define RESTORE     {__BNF_level = hold___BNF_level; __BNF_input = hold___BNF_input; __BNF_output = hold___BNF_output;}

#ifdef __TURBOC__
# pragma warn -pro
# pragma warn -nod
#endif

#ifdef _MSC_VER
# pragma warning (disable:4013)
# pragma warning (disable:4005)
#endif

/*
    externals:
*/

extern char *__BNF_input, *__BNF_output;
extern unsigned __BNF_level;
extern unsigned int __BNF_tabsize;

extern int __BNF_trans_string(char *),
    __BNF_input_string(char *), __BNF_output_string(char *),
    __BNF_trans_char(void), __BNF_swap(char *, char *, char *);


extern void user_error(char *); /* user provided error handler must TERMINATE */



int w_(void)
{
	int state;

	{
		int firstloop = 1;
		do {
			state = __BNF_trans_string( " "  ); /* --- Call function --- */
			if (firstloop)
			{
				if (state) break;
				firstloop = 0;
			}
		} while ( !state );
		state = firstloop;
	}
	state = 0;
	return state;}


int _w(void)
{
	int state;

	{
		int firstloop = 1;
		do {
			state = __BNF_input_string( " "  ); /* --- Call function --- */
			if (firstloop)
			{
				if (state) break;
				firstloop = 0;
			}
		} while ( !state );
		state = firstloop;
	}
	state = 0;
	return state;}


int ynanswer(void)
{
	int state;

	do {
		do {
			HOLD;

			do {
				do {
					HOLD;

					state = __BNF_input_string( "yes"  ); /* --- Call function --- */
					if (state) break;
					do {
						HOLD;

						state = w_( ); /* --- Call function --- */
						if (state) break;
						state = __BNF_input_string( "please"  ); /* --- Call function --- */
						if (state) { RESTORE; break; };
					} while( 0 );

					state = 0;
					if (state) { RESTORE; break; };
				} while( 0 );

				if (!state) break;
				state = __BNF_input_string( "yeah"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_input_string( "okay"  ); /* --- Call function --- */
			} while( 0 );

			if (state) break;
			state = __BNF_output_string( "yes"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			do {
				do {
					HOLD;

					state = __BNF_input_string( "no"  ); /* --- Call function --- */
					if (state) break;
					do {
						HOLD;

						state = w_( ); /* --- Call function --- */
						if (state) break;
						state = __BNF_input_string( "thank"  ); /* --- Call function --- */
						if (state) { RESTORE; break; };
						state = w_( ); /* --- Call function --- */
						if (state) { RESTORE; break; };
						state = __BNF_input_string( "you"  ); /* --- Call function --- */
						if (state) { RESTORE; break; };
					} while( 0 );

					state = 0;
					if (state) { RESTORE; break; };
				} while( 0 );

				if (!state) break;
				state = __BNF_input_string( "nope"  ); /* --- Call function --- */
			} while( 0 );

			if (state) break;
			state = __BNF_output_string( "no"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int weapon(void)
{
	int state;

	do {
		state = __BNF_trans_string( "axe"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "wand"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "rod"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int article(void)
{
	int state;

	state = __BNF_input_string( "the"  ); /* --- Call function --- */
	return state;}


int lamp_item(void)
{
	int state;

	do {
		state = __BNF_trans_string( "lamp"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "lantern"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "light"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "headlight"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "head"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "lamp"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int item(void)
{
	int state;

	do {
		state = weapon( ); /* --- Call function --- */
		if (!state) break;
		state = lamp_item( ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "battery"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "carpet"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "barrel"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "gold"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = __BNF_input_string( "gold"  ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			state = __BNF_trans_string( "nugget"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "diamond"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = __BNF_input_string( "silver"  ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			state = __BNF_trans_string( "bars"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "silver"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "jewel"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "coins"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "chest"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "box"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "treasure"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "eggs"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "egg"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "nest"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "trident"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = __BNF_input_string( "ming"  ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			state = __BNF_trans_string( "vase"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "shards"  ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = __BNF_input_string( "of"  ); /* --- Call function --- */
				if (state) { RESTORE; break; };
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
				state = __BNF_input_string( "pottery"  ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "pottery"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "emerald"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "platinum"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "pyramid"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "platinum"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "pyramid"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "pearl"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = __BNF_input_string( "persian"  ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			state = __BNF_trans_string( "rug"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "spice"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "chain"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "vending"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "machine"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "knife"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "knives"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "food"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "rations"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "bottle"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "jar"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "water"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "oil"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "debris"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "shell"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "keys"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "key"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "grate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "cage"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "pillow"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "velvet"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "tablet"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "magazine"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "issue"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "mirror"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "mist"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "lock"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "nothing"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "oyster"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "clam"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int organism(void)
{
	int state;

	do {
		state = __BNF_trans_string( "troll"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "bear"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "dragon"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "bird"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "pirate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "dwarf"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "dwarves"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "snake"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "clam"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "oyster"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "plant"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "giant"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "shadow"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "figure"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int voice_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "say"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "chant"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "sing"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "utter"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "mumble"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int location(void)
{
	int state;

	do {
		state = __BNF_trans_string( "depression"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "road"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hill"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "forest"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "valley"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "gully"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "stream"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "passage"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "tunnel"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "chasm"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "fissure"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "pit"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "outdoor"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "outdoors"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "crack"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "cave"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "entrance"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "slit"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "slab"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "tree"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "trees"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "bed"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "quilt"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "office"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "cavern"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "floor"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "house"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "dome"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hall"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "view"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "staircase"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "stairs"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "steps"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "oriental"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "room"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "reservoir"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "volcano"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "geyser"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hole"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "wall"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "message"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "low"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "room"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "building"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "drawings"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "door"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "grate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "fork"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "bed"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "moss"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "carpet"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			do {
				state = __BNF_trans_string( "awkward"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "secret"  ); /* --- Call function --- */
			} while( 0 );

			state = 0;
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "canyon"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "broken"  ); /* --- Call function --- */
			state = 0;
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "rock"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "main"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			do {
				state = __BNF_trans_string( "corridor"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "office"  ); /* --- Call function --- */
			} while( 0 );

			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			do {
				state = __BNF_trans_string( "debris"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "dark"  ); /* --- Call function --- */
			} while( 0 );

			state = 0;
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "room"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "low"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			do {
				state = __BNF_trans_string( "window"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "passage"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "tunnel"  ); /* --- Call function --- */
			} while( 0 );

			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int move_action(void)
{
	int state;

	do {
		state = __BNF_trans_string( "enter"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "return"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "jump"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "climb"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "retreat"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "retread"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "continue"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "walk"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "run"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "exit"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "leave"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "crawl"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "ascend"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "descend"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "cross"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "swim"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int ambiguous_move_action(void)
{
	int state;

	do {
		state = __BNF_trans_string( "travel"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "proceed"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "go"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "explore"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "follow"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "turn"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int unambiguous_direction(void)
{
	int state;

	do {
		do {
			HOLD;

			state = __BNF_trans_string( "up"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "stream"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "down"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "stream"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "forward"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "onward"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "back"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "outside"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "inward"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "nowhere"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "downward"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "left"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "right"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "upward"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "east"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "west"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "north"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "south"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int explosive_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "blast"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "detonate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "ignite"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "blow"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "up"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int attack_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "attack"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "kill"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "slay"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "fight"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hit"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "strike"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "smash"  ); /* --- Call function --- */
		if (!state) break;
		state = explosive_verb( ); /* --- Call function --- */
	} while( 0 );

	return state;}


int magic_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "abra"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "abracadabra"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "hocus"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "pocus"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "x"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "y"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "z"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "z"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "y"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_output_string( "xyzzy"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_trans_string( "open"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "sesame"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int item_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "carry"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "pick"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "up"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_output_string( "take"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "take"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "keep"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "catch"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "steal"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "capture"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "get"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "tote"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "drop"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "release"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "free"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "discard"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "dump"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "throw"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "toss"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "find"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "rub"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "fill"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "shatter"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "break"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "read"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "peruse"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int menu_action(void)
{
	int state;

	do {
		do {
			HOLD;

			state = __BNF_trans_string( "where"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "am"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "i"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "i"  ); /* --- Call function --- */
			if (state) break;
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_input_string( "am"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = _w( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = __BNF_trans_string( "lost"  ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "help"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "inventory"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "suspend"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "pause"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "save"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "stop"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "quit"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hours"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "score"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "info"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "information"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "brief"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int examine_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "describe"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "look"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "examine"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "touch"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int item_to_open_close(void)
{
	int state;

	do {
		state = __BNF_trans_string( "door"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "grate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "house"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "oyster"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "clam"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "chain"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "jar"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "bottle"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int open_close_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "unlock"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "open"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "lock"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "close"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int digging_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "dig"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "excavate"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int animal_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "feed"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "calm"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "tame"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "placate"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "wake"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "disturb"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int animal_action(void)
{
	int state;

	do {
		HOLD;

		state = animal_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			state = article( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = organism( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int explosive_action(void)
{
	int state;

	do {
		HOLD;

		state = explosive_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			state = article( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = location( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int target(void)
{
	int state;

	do {
		state = organism( ); /* --- Call function --- */
		if (!state) break;
		state = item( ); /* --- Call function --- */
	} while( 0 );

	return state;}


int fight_action(void)
{
	int state;

	do {
		HOLD;

		state = attack_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = article( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = target( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int attack_item_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "wave"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "shake"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "swing"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int attack_item_action(void)
{
	int state;

	do {
		HOLD;

		state = attack_item_verb( ); /* --- Call function --- */
		if (state) break;
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		do {
			HOLD;

			state = article( ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = item( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int food_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "pour"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "eat"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "devour"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "drink"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int food_action(void)
{
	int state;

	do {
		HOLD;

		state = food_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			state = article( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = target( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int off_on(void)
{
	int state;

	do {
		state = __BNF_trans_string( "on"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "off"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int lamp_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "light"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "extinguish"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "turn"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = off_on( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int lamp_action(void)
{
	int state;

	do {
		do {
			HOLD;

			state = lamp_verb( ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = article( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = lamp_item( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "turn"  ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = article( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = lamp_item( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = off_on( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int digging_action(void)
{
	int state;

	do {
		HOLD;

		state = digging_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = article( ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = location( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int item_action(void)
{
	int state;

	do {
		HOLD;

		state = item_verb( ); /* --- Call function --- */
		if (state) break;
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		do {
			HOLD;

			state = article( ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = item( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int magic_action(void)
{
	int state;

	do {
		HOLD;

		do {
			HOLD;

			state = voice_verb( ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) break;
		state = magic_verb( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int examine_target(void)
{
	int state;

	do {
		state = location( ); /* --- Call function --- */
		if (!state) break;
		state = item( ); /* --- Call function --- */
		if (!state) break;
		state = organism( ); /* --- Call function --- */
	} while( 0 );

	return state;}


int examine_action(void)
{
	int state;

	do {
		HOLD;

		state = examine_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = __BNF_input_string( "at"  ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = article( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = examine_target( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int fluid_verb(void)
{
	int state;

	do {
		state = __BNF_trans_string( "water"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "oil"  ); /* --- Call function --- */
	} while( 0 );

	return state;}


int fluid_action(void)
{
	int state;

	do {
		HOLD;

		state = fluid_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			state = article( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = target( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int open_close_action(void)
{
	int state;

	do {
		HOLD;

		state = open_close_verb( ); /* --- Call function --- */
		if (state) break;
		do {
			HOLD;

			state = w_( ); /* --- Call function --- */
			if (state) break;
			state = article( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		state = 0;
		if (state) { RESTORE; break; };
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = item_to_open_close( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int opt_of(void)
{
	int state;

	do {
		HOLD;

		state = w_( ); /* --- Call function --- */
		if (state) break;
		state = __BNF_input_string( "of"  ); /* --- Call function --- */
		state = 0;
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int modifier_direction(void)
{
	int state;

	do {
		state = __BNF_input_string( "to"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "into"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "on"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "off"  ); /* --- Call function --- */
			if (state) break;
			state = opt_of( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int opt_modifier_direction_nooutput(void)
{
	int state;

	do {
		do {
			HOLD;

			do {
				state = __BNF_input_string( "inside"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_input_string( "out"  ); /* --- Call function --- */
			} while( 0 );

			if (state) break;
			state = opt_of( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_input_string( "in"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "up"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "above"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "down"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "across"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "over"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_input_string( "under"  ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = __BNF_input_string( "onto"  ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	state = 0;
	return state;}


int opt_modifier_direction_output(void)
{
	int state;

	do {
		do {
			HOLD;

			do {
				state = __BNF_trans_string( "inside"  ); /* --- Call function --- */
				if (!state) break;
				state = __BNF_trans_string( "out"  ); /* --- Call function --- */
			} while( 0 );

			if (state) break;
			state = opt_of( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = __BNF_trans_string( "in"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "up"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "above"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "down"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "across"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "over"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "under"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "onto"  ); /* --- Call function --- */
	} while( 0 );

	state = 0;
	return state;}


int directional_phrase(void)
{
	int state;

	do {
		state = unambiguous_direction( ); /* --- Call function --- */
		if (!state) break;
		do {
			HOLD;

			state = modifier_direction( ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = article( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = location( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = opt_modifier_direction_nooutput( ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = article( ); /* --- Call function --- */
				if (state) break;
				state = w_( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
			state = location( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		state = opt_modifier_direction_output( ); /* --- Call function --- */
	} while( 0 );

	return state;}


int move_phrase(void)
{
	int state;

	do {
		do {
			HOLD;

			state = move_action( ); /* --- Call function --- */
			if (state) break;
			do {
				HOLD;

				state = w_( ); /* --- Call function --- */
				if (state) break;
				state = directional_phrase( ); /* --- Call function --- */
				if (state) { RESTORE; break; };
			} while( 0 );

			state = 0;
			if (state) { RESTORE; break; };
		} while( 0 );

		if (!state) break;
		do {
			HOLD;

			state = ambiguous_move_action( ); /* --- Call function --- */
			if (state) break;
			state = w_( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
			state = directional_phrase( ); /* --- Call function --- */
			if (state) { RESTORE; break; };
		} while( 0 );

	} while( 0 );

	return state;}


int thing_to_say(void)
{
	int state;

	do {
		state = item( ); /* --- Call function --- */
		if (!state) break;
		state = organism( ); /* --- Call function --- */
		if (!state) break;
		state = location( ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hello"  ); /* --- Call function --- */
		if (!state) break;
		state = __BNF_trans_string( "hi"  ); /* --- Call function --- */
		if (!state) break;
		state = ynanswer( ); /* --- Call function --- */
	} while( 0 );

	return state;}


int voice_action(void)
{
	int state;

	do {
		HOLD;

		state = voice_verb( ); /* --- Call function --- */
		if (state) break;
		state = w_( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
		state = thing_to_say( ); /* --- Call function --- */
		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}


int command(void)
{
	int state;

	do {
		HOLD;

		state = _w( ); /* --- Call function --- */
		if (state) break;
		do {
			state = voice_action( ); /* --- Call function --- */
			if (!state) break;
			state = move_phrase( ); /* --- Call function --- */
			if (!state) break;
			state = open_close_action( ); /* --- Call function --- */
			if (!state) break;
			state = fluid_action( ); /* --- Call function --- */
			if (!state) break;
			state = food_action( ); /* --- Call function --- */
			if (!state) break;
			state = menu_action( ); /* --- Call function --- */
			if (!state) break;
			state = examine_action( ); /* --- Call function --- */
			if (!state) break;
			state = magic_action( ); /* --- Call function --- */
			if (!state) break;
			state = item_action( ); /* --- Call function --- */
			if (!state) break;
			state = lamp_action( ); /* --- Call function --- */
			if (!state) break;
			state = digging_action( ); /* --- Call function --- */
			if (!state) break;
			state = explosive_action( ); /* --- Call function --- */
			if (!state) break;
			state = fight_action( ); /* --- Call function --- */
			if (!state) break;
			state = attack_item_action( ); /* --- Call function --- */
			if (!state) break;
			state = animal_action( ); /* --- Call function --- */
		} while( 0 );

		if (state) { RESTORE; break; };
	} while( 0 );

	return state;}



/* begining of standard utility functions */



#include <stdio.h> /* for EOF */
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*#define HOLD        unsigned hold___BNF_level = __BNF_level; char *hold___BNF_input = __BNF_input, *hold___BNF_output = __BNF_output
#define RESTORE     {__BNF_level = hold___BNF_level, __BNF_input = hold___BNF_input; __BNF_output = hold___BNF_output;}*/
#define DEFUN(f)    int f(void)
#define CALL(f)     state = f();
#define IN__BNF_put(s)    state = __BNF_input_string( s );
#define OUT__BNF_put(s)   state = __BNF_output_string( s );
#define FUN_begin   { int state; HOLD;
#define FUN_end     if (state) RESTORE; return state; }
#define AND_begin   do { HOLD;
#define AND_1       if (state) break;
#define AND_2       if (state) { RESTORE; break; }
#define AND_end     } while (0);
#define OR_begin    do {
#define OR_1        if (!state) break;
#define OR_end      } while (0);
#define OPT_begin
#define OPT_end     state = 0;
#define REP_begin   { inte firstloop=1; do {
#define REP_end     if (firstloop) {if(state) break; firstloop=0;} } while (!state); state=firstloop; }

extern char *__BNF_input, *__BNF_output;
unsigned __BNF_level;
unsigned int __BNF_rulecnt;
/* we need some prototypes .... */
int __BNF_get(void);          /* returns EOF when eof read... */
int __BNF_flush(void);
#define __BNF_put(ch) *__BNF_output++ = (ch)

int __BNF_input_string( char *s )
FUN_begin
  char *t;

  for (t = s, state = 0; *t; t++)
    if ((state = (__BNF_get() != *t)) != 0) break;

FUN_end

int __BNF_output_string( char *source )
{
    register char *s = source, *t = __BNF_output;

    while ( *s ) *t++ = *s++;

    __BNF_output = t;

    return 0;
}


int __BNF_trans_string( char *str )
FUN_begin
  char *s, ch;

  for ( s = str; *s; s++) {
        ch = __BNF_get();
        if ( ch == *s )
          __BNF_put( ch );
        else {
          RESTORE;
          return 1;
        }
  }
  state = 0;

FUN_end

int __BNF_swap( char *first, char *second, char *third )
{
        unsigned len1 = second - first, len2 = third - second;
        char *hold = strncpy( (char *) malloc(len1+1), first, len1 );

        strncpy( first, second, len2 );
        strncpy( first+len2, hold, len1 );

        free(hold);
    return 0;
}

DEFUN(__BNF_trans_char)
FUN_begin
  int ch;

  if ( (state = ((ch = __BNF_get()) == EOF)) == 0) __BNF_put( ch );
FUN_end

DEFUN(eoi)
FUN_begin
  state = !(__BNF_get() == EOF);
FUN_end

DEFUN(commentchars)
{
        register char ch;

        for ( ch = __BNF_get(); ch != '\n'; ch = __BNF_get() )
                __BNF_put(ch);

        --__BNF_input;

        return 0;
}


int ignorechars (void)
{
   int   ch;

   ch = __BNF_get();
   while ( ch != '\n' && ch != EOF )
      ch = __BNF_get();
   -- __BNF_input;
   return   0;
}

DEFUN(stringchar)
FUN_begin
  int ch=__BNF_get();

  state = !(isprint( ch ) && ch != '\n' && ch != '\'');

  if ( ch == '\\' ) {
    ch = __BNF_get();
    if ( !state ) {
      state = !isprint( ch );
      if (!state) {
        __BNF_put( '\\' );
        __BNF_put( ch );
      }
    }
  }
  else
    if ( !state ) __BNF_put( ch );

FUN_end

DEFUN(o_stringchar)
FUN_begin
  int ch=__BNF_get();

  state = !(isprint( ch ) && ch != '\n' && ch != '`');

  if ( ch == '\\' ) {
    ch = __BNF_get();
    if ( !state ) {
      state = !isprint( ch );
      if (!state) {
        *__BNF_output++ = '\\';
        *__BNF_output++ = ch;
      }
    }
  }
  else
    if ( !state ) *__BNF_output++ = ch ;
FUN_end

DEFUN(t_stringchar)
FUN_begin
  int ch=__BNF_get();

  state = !(isprint( ch ) && ch != '\n' && ch != '"');

  if ( ch == '\\' ) {
    ch = __BNF_get();
    if ( !state ) {
      state = !isprint( ch );
      if (!state)
        {       __BNF_put( '\\' );
                __BNF_put( ch );
        }
    }
  }
  else
    if ( !state ) __BNF_put( ch );
FUN_end

DEFUN(letter)
FUN_begin
  int ch=__BNF_get();

  state = !(isalpha( ch ) || ch == '_');

  if (state)
    RESTORE
  else
    __BNF_put( ch );
FUN_end

DEFUN(digit)
FUN_begin
  int ch = __BNF_get();

  state = !isdigit( ch );

  if (state)
    RESTORE
  else
    __BNF_put( ch );
FUN_end

DEFUN(special)
FUN_begin
  int ch = __BNF_get();

  state = !isgraph( ch );

  if (state)
    RESTORE
  else
    __BNF_put( ch );

FUN_end

DEFUN(control)
FUN_begin
  int ch = __BNF_get();

  state = !iscntrl( ch );

  if (state)
    RESTORE
  else
    __BNF_put( ch );
FUN_end

DEFUN(character)
FUN_begin
  OR_begin
    CALL(stringchar)
  OR_1
    CALL(control)
  OR_end
FUN_end


DEFUN(white)
FUN_begin

  state = !isspace( __BNF_get() );

  if ( !state ) {
    while ( isspace( __BNF_get() ) )
        ;
    --__BNF_input;
  };

FUN_end

DEFUN(inc_level)
FUN_begin
        ++__BNF_level;

        state=0;
FUN_end

DEFUN(dec_level)
FUN_begin
        --__BNF_level;

        state=0;
FUN_end

DEFUN(out_indent)
FUN_begin
        unsigned i,j;

        for (i=0; i<__BNF_level; i++ )
            if (__BNF_tabsize) {
                for(j=0;j<__BNF_tabsize;j++) __BNF_put(' ');
            }
            else
                __BNF_put('	');

        state=0;
FUN_end



int inc_rule (void)
{
   ++ __BNF_rulecnt;
   return   0;
}

int flush( void )
{
  return __BNF_flush();
}

/* eof */





#include <stdio.h>

/****************************************************************************************
 * We have either a strings or files as input and output.
 */

int __BNF_str_io_parser(char* input,char* output,int (*syntax)());
int __BNF_fil_io_parser(FILE* input,FILE* output,int (*syntax)());

/****************************************************************************************
 * STRIO/FILIO COMMON DEFS
 */

#include <stdlib.h>

#define BUFFER_SIZE   (8*20480)

unsigned __BNF_err_line;
unsigned long __BNF_no_read, __BNF_no_written;
char *__BNF_input, *__BNF_output;
unsigned int __BNF_tabsize = 0;

static int __is_file_io = 0;

/****************************************************************************************
 * FILIO
 */


FILE *if_ptr = NULL, *of_ptr = NULL;
static char  *max___BNF_input;
static char *__BNF_input_buffer = NULL, *__BNF_output_buffer = NULL;


static int init(void);
static int done(void);

int __BNF_fil_io_parser( FILE *input, FILE *output, int (*syntax)() )
{
        int retval;

  __is_file_io = 1;

                /* --- initialisation --- */

        __BNF_level = __BNF_rulecnt = 0;
        if_ptr = input;
        of_ptr = output;

        if ( init() ) {
                fprintf( stderr, "Fatal: Cannot allocate enough memory.\n" );
                return 1;
        }
                /* --- call the syntax parser --- */
        retval = (*syntax)();

                /* --- clean up --- */
        done();

        return retval;
}

int __BNF_fil_get(void)
{
  int ch;

  if ( __BNF_input == max___BNF_input ) {
    if ( (ch = fgetc(if_ptr)) != 0 ) {
      *__BNF_input++ = ch;
      max___BNF_input++;
      __BNF_no_read++;
    }
    if ( ch == '\n' ) __BNF_err_line++;
    return ch;
  }
  else
    return *__BNF_input++;
}

int __BNF_fil_put(int ch)
{
  if ( __BNF_output == __BNF_output_buffer+BUFFER_SIZE ) {
    return 1;
  }

  *__BNF_output++ = ch;
  return 0;
}

int __BNF_fil_flush(void)
{

  char *s = __BNF_output_buffer;

  while ( s < __BNF_output ) {
    __BNF_no_written++;
    fputc( *s++, of_ptr );
  }
  __BNF_output = __BNF_output_buffer;

  return 0;
}


static int init(void)
{
  if ( (__BNF_input_buffer = malloc( BUFFER_SIZE )) != NULL ) {
    if ( (__BNF_output_buffer = malloc( BUFFER_SIZE )) != NULL ) {
      __BNF_input = max___BNF_input = __BNF_input_buffer;
      __BNF_output = __BNF_output_buffer;

      __BNF_no_read = 0;
      __BNF_no_written = 0;
      __BNF_err_line=1;
  return 0;
}
else
      free( __BNF_input_buffer );
  }

  return 1;
}

static int done(void)
{
  __BNF_flush();

  free( __BNF_output_buffer);
  free( __BNF_input_buffer );

  __BNF_input_buffer = 0;
  __BNF_output_buffer = 0;

  return 0;
}

/****************************************************************************************
* STRIO
****************************************************************************************/

int __BNF_str_io_parser( char *input, char *output, int (*syntax)() )
{
       int retval;
       char *s;
       __is_file_io = 0;

       /* --- initialisation --- */
       __BNF_input = max___BNF_input = __BNF_input_buffer = input;
       __BNF_output = __BNF_output_buffer = output;
       __BNF_no_read = __BNF_no_written = 0;
       __BNF_err_line = 1;
       __BNF_level = __BNF_rulecnt = 0;

       /* --- call the syntax parser --- */
       retval = syntax();

       /* --- count the number of output-bytes --- */
       for ( s = __BNF_output_buffer; s < __BNF_output ; s++ )
               ++ __BNF_no_written;

       return retval;
}

int __BNF_str_get( void )
{
       register ch;

       if ( __BNF_input == max___BNF_input ) {
               
               if ( (ch = *max___BNF_input) != '\0' ) {
                       ++ max___BNF_input;
                       ++ __BNF_input;
                       ++ __BNF_no_read;
                       
                       if ( ch == '\n' ) __BNF_err_line++;
                       
                       return ch;
               }
               else
                       return EOF;
       }
       else
               return *__BNF_input++;
}

int __BNF_str_put( int ch )
{
       *__BNF_output++ = ch;
       return 0;
}


int __BNF_str_flush( void )
{
       return 0;
}


/****************************************************************************************
* STRIO/FILIO COMMON HOOKS
****************************************************************************************/


#if 0
int __BNF_put(int ch)
{
       return (__is_file_io == 1) ? __BNF_fil_put(ch) : __BNF_str_put(ch);
}
#endif
int __BNF_get(void)
{
       return (__is_file_io == 1) ? __BNF_fil_get() : __BNF_str_get();
}
int __BNF_flush(void)
{
       return (__is_file_io == 1) ? __BNF_fil_flush() : __BNF_str_flush();
}


