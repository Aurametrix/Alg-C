/* 
   A simple test program to parse XML documents with expat
   <http://expat.sourceforge.net/>. It just displays the element
   names.

   On Debian, compile with:

   gcc -Wall -o expat-test -lexpat expat-test.c  

   Inspired from <http://www.xml.com/pub/a/1999/09/expat/index.html> 
*/

#include <expat.h>
#include <stdio.h>
#include <string.h>

/* Keep track of the current level in the XML tree */
int             Depth;

#define MAXCHARS 1000000

void
start(void *data, const char *el, const char **attr)
{
    int             i;

    for (i = 0; i < Depth; i++)
    	printf("  ");

    printf("%s", el);

    for (i = 0; attr[i]; i += 2) {
    	printf(" %s='%s'", attr[i], attr[i + 1]);
    }

    printf("\n");
    Depth++;
}   			/* End of start handler */

void
end(void *data, const char *el)
{
    Depth--;
}   			/* End of end handler */

int
main(int argc, char **argv)
{

    char           *filename;
    FILE           *f;
    size_t          size;
    char           *xmltext;
    XML_Parser      parser;

    if (argc != 2) {
    	fprintf(stderr, "Usage: %s filename\n", argv[0]);
    	return (1);
    }
    filename = argv[1];
    parser = XML_ParserCreate(NULL);
    if (parser == NULL) {
    	fprintf(stderr, "Parser not created\n");
    	return (1);
    }
    /* Tell expat to use functions start() and end() each times it encounters
     * the start or end of an element. */
    XML_SetElementHandler(parser, start, end);
    f = fopen(filename, "r");
    xmltext = malloc(MAXCHARS);
    /* Slurp the XML file in the buffer xmltext */
    size = fread(xmltext, sizeof(char), MAXCHARS, f);
    if (XML_Parse(parser, xmltext, strlen(xmltext), XML_TRUE) ==
        XML_STATUS_ERROR) {
    	fprintf(stderr,
    		"Cannot parse %s, file may be too large or not well-formed XML\n",
    		filename);
    	return (1);
    }
    fclose(f);
    XML_ParserFree(parser);
    fprintf(stdout, "Successfully parsed %i characters in file %s\n", size,
    	filename);
    return (0);
}
