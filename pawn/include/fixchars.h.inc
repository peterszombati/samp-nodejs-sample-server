//------------------------------------------------------------------------------
// Ez a függvénykönyvtár jaívtja a hibás magyar karaktereket a képernyõre megje-
// lenõ szövegekben (lásd GameText,TextDraw stb), tesztelve lett, és mûködik.
//
// Készítette Gamestar 2010/JAN/20
// FRISSÍTVE 2010 FEBRUÁR 28
//------------------------------------------------------------------------------

static chlist[][0]={
	"¨","‘","ö","Ö",
    "¬","•","ü","Ü",
 	"¦","","ó","Ó",
 	"§","","õ","Õ",
 	"ª","“","ú","Ú",
 	"","‡","é","É",
 	"˜","","á","Á",
	"«","·","û","Û",
	"¢","‹","í","Í"
};

stock fixchars_GameTextForPlayer(playerid,text[],time,style)
{
	return GameTextForPlayer(playerid,FixGameStringFixchars(text),time,style);
}
#define GameTextForPlayer fixchars_GameTextForPlayer

//*******************

stock fixchars_GameTextForAll(text[],time,style)
{
	return GameTextForAll(FixGameString(text),time,style);
}
#define GameTextForAll fixchars_GameTextForAll

//*******************

stock Text:fixchars_TextDrawCreate(Float:x, Float:y, text[])
{
	return TextDrawCreate(x,y,FixGameString(text));
}
#define TextDrawCreate fixchars_TextDrawCreate

//*******************

stock Menu:fixchars_CreateMenu(const title[], columns, Float:x, Float:y, Float:col1width, Float:col2width = 0.0)
{
	return CreateMenu(FixGameString(title),columns,x,y,col1width,col2width);
}
#define CreateMenu fixchars_CreateMenu

//*******************

stock fixchars_SetMenuColumnHeader(Menu:menuid, column, const columnheader[])
{
	return SetMenuColumnHeader(menuid, column, FixGameString(columnheader));
}
#define SetMenuColumnHeader fixchars_SetMenuColumnHeader

//*******************

stock fixchars_AddMenuItem(Menu:menuid, column, const menutext[])
{
 	return AddMenuItem(menuid, column, FixGameString(menutext));
}
#define AddMenuItem fixchars_AddMenuItem

//*******************

stock fixchars_TextDrawSetString(Text:text, StringFixchars[])
{
	return TextDrawSetString(text,FixGameString(StringFixchars));
}
#define TextDrawSetString fixchars_TextDrawSetString

//*******************
stock FixGameString(const StringFixchars[])
{
	// Tárolók létrehozása
	new index,
	    dest[256];
	
	// Karakterlánc átmásolása
	strmid(dest,StringFixchars,0,strlen(StringFixchars),sizeof dest);

	// Végiglépkedünk a karaktereken
	for(index = 0; index < strlen(dest); index++)
	{
	    // Végiglépkedünk a karaktertömbön
		for(new idx = 0; idx < sizeof(chlist); idx++)
		{
		    // Ha az indexelt karakterek egyeznek
		    if(dest[index] == chlist[idx][0])
		    {
		        // Javítjuk
		        dest[index] = chlist[idx-2][0];
			}
		}
	}

	// Visszatérés
	return dest;
}
