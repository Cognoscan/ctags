/*
*   Copyright (c) 2013, Richard Scott Teal (Scott@Teals.org)
*
*   This source code is released for free distribution under the terms of the
*   GNU General Public License.
*
*   This module generates tags for VHDL files using regular expressions and
*   callback functions.
*/

/*
 *   INCLUDE FILES
 */
#include "general.h"    /* always include first */
#include "parse.h"      /* always include */

/* FUNCTION DEFINITIONS */

static void installVhdlRegex (const langType language)
{
  addTagRegex (language ,  "^[ \t]*package[ \t]+([^ ]+) is"              ,  "\\1" ,  "d,package declarations"        ,  "i");
  addTagRegex (language ,  "^[ \t]*package[ \t]+body[ \t]+([^ ]+) is"    ,  "\\1" ,  "b,package bodies"              ,  "i");
  addTagRegex (language ,  "^[ \t]*architecture[ \t]+([^ ]+) of"         ,  "\\1" ,  "a,architecture specifications" ,  "i");
  addTagRegex (language ,  "^[ \t]*entity[ \t]+([^ ]+) is"               ,  "\\1" ,  "e,entities"                    ,  "i");
  addTagRegex (language ,  "^[ \t]*([^ \t:]+)[ \t]*:[ \t]*process[ \t]*" ,  "\\1" ,  "p,processes"                   ,  "i");
  addTagRegex (language ,  "^[ \t]*function[ \t]+([a-z0-9_]+)"           ,  "\\1" ,  "f,functions"                   ,  "i");
  addTagRegex (language ,  "^[ \t]*procedure[ \t]+([a-z0-9_]+)"          ,  "\\1" ,  "P,procedures"                  ,  "i");
  addTagRegex (language ,  "^[ \t]*type[ \t]+([^ ]+) is"                 ,  "\\1" ,  "t,type declarations"           ,  "i");
  addTagRegex (language ,  "^[ \t]*constant[ \t]+([a-z0-9_]+)[ \t]*:"    ,  "\\1" ,  "c,constant declarations"       ,  "i");
  addTagRegex (language ,  "^[ \t]*signal[ \t]+([a-z0-9_]+)[ \t]*:"      ,  "\\1" ,  "s,signal declarations"         ,  "i");
  addTagRegex (language ,  "^[ \t]*([a-z0-9_]+)[ \t]*:[ \t]*([a-z0-9_]+)"      ,  "\\1" ,  "i,instantiations"         ,  "i");
}

/* Create parser definition stucture */
extern parserDefinition *VhdlParser (void)
{
    static const char *const patterns [] = { NULL };
  static const char *const extensions[] = { "vhdl", "vhd", NULL };
  parserDefinition* const def = parserNew ("VHDL");
  def->patterns = patterns;
  def->extensions = extensions;
  def->initialize = installVhdlRegex;
  def->regex = TRUE;
  return def;
}

