/* UNIX V7 source code: see /COPYRIGHT or www.tuhs.org for details. */

# include "refer..c"
static char ahead[1000];
static int peeked = 0;
static int noteof = 1;
input (s)
	char *s;
{
if (peeked)
	{
	peeked=0;
	if (noteof==0) return(0);
	strcpy (s, ahead);
	return(s);
	}
return(fgets(s, 1000, in));
}
lookat()
{
if (peeked) return(ahead);
noteof=input(ahead);
peeked=1;
return(noteof);
}
addch(s, c)
	char *s;
{
while (*s) s++;
*s++ = c;
*s = 0;
}
