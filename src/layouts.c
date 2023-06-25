/*
 * layouts.c
 *
 *  Created on: 25. 6. 2023
 *      Author: stanislaw
 */


#include "layouts.h"

extern char * kbd_strings[80];
extern char * kbd_strings_sh[80];
extern char * kbd_strings_alt[80];
extern char * kbd_strings_nmlk[80];
extern char * kbd_strings_czlk[80];

void init_kbd_strings () {
  kbd_strings[0] = "#esc";
  kbd_strings[1] = "#f1";
  kbd_strings[2] = "#f2";
  kbd_strings[3] = "#f3";
  kbd_strings[4] = "#f4";
  kbd_strings[5] = "#f5";
  kbd_strings[6] = "#f6";
  kbd_strings[7] = "#f7";
  kbd_strings[8] = "#f8";
  kbd_strings[9] = "#f9";
  kbd_strings[10] = "#f10";
  kbd_strings[11] = "#nmlk";
  kbd_strings[12] = "#prtscr";
  kbd_strings[13] = "#ins";
  kbd_strings[14] = "#del";

  kbd_strings[15] = ";";
  kbd_strings[16] = "1";
  kbd_strings[17] = "2";
  kbd_strings[18] = "3";
  kbd_strings[19] = "4";
  kbd_strings[20] = "5";
  kbd_strings[21] = "6";
  kbd_strings[22] = "7";
  kbd_strings[23] = "8";
  kbd_strings[24] = "9";
  kbd_strings[25] = "0";
  kbd_strings[26] = "-";
  kbd_strings[27] = "#bksp";

  kbd_strings[28] = "#tab";
  kbd_strings[29] = "q";
  kbd_strings[30] = "w";
  kbd_strings[31] = "e";
  kbd_strings[32] = "r";
  kbd_strings[33] = "t";
  kbd_strings[34] = "y";
  kbd_strings[35] = "u";
  kbd_strings[36] = "i";
  kbd_strings[37] = "o";
  kbd_strings[38] = "p";
  kbd_strings[39] = "=";
  kbd_strings[40] = "ů";

  kbd_strings[41] = "#cplk";
  kbd_strings[42] = "a";
  kbd_strings[43] = "s";
  kbd_strings[44] = "d";
  kbd_strings[45] = "f";
  kbd_strings[46] = "g";
  kbd_strings[47] = "h";
  kbd_strings[48] = "j";
  kbd_strings[49] = "k";
  kbd_strings[50] = "l";
  kbd_strings[51] = ";";
  kbd_strings[52] = "#ent";

  kbd_strings[53] = "#lsft";
  kbd_strings[54] = "\\"; // same key twice
  kbd_strings[55] = "z";
  kbd_strings[56] = "x";
  kbd_strings[57] = "c";
  kbd_strings[58] = "v";
  kbd_strings[59] = "b";
  kbd_strings[60] = "n";
  kbd_strings[61] = "m";
  kbd_strings[62] = ",";
  kbd_strings[63] = ".";
  kbd_strings[64] = "/";
  kbd_strings[65] = "#up";
  kbd_strings[66] = "#rsft";

  kbd_strings[67] = "#fn";
  kbd_strings[68] = "#ctrl";
  kbd_strings[69] = "#zzz";
  kbd_strings[70] = "#alt";
  kbd_strings[71] = "#brk";
  kbd_strings[72] = " ";
  kbd_strings[73] = "#menu";
  kbd_strings[74] = "[";
  kbd_strings[75] = "]";
  kbd_strings[76] = "'";
  kbd_strings[77] = "#left";
  kbd_strings[78] = "#dn";
  kbd_strings[79] = "#right";
}

void init_kbd_strings_sh() {
  kbd_strings_sh[0] = "#esc";
  kbd_strings_sh[1] = "#f1";
  kbd_strings_sh[2] = "#f2";
  kbd_strings_sh[3] = "#f3";
  kbd_strings_sh[4] = "#f4";
  kbd_strings_sh[5] = "#f5";
  kbd_strings_sh[6] = "#f6";
  kbd_strings_sh[7] = "#f7";
  kbd_strings_sh[8] = "#f8";
  kbd_strings_sh[9] = "#f9";
  kbd_strings_sh[10] = "#f10";
  kbd_strings_sh[11] = "#nmlk";
  kbd_strings_sh[12] = "#prtscr";
  kbd_strings_sh[13] = "#ins";
  kbd_strings_sh[14] = "#del";

  kbd_strings_sh[15] = "~";
  kbd_strings_sh[16] = "!";
  kbd_strings_sh[17] = "@";
  kbd_strings_sh[18] = "#";
  kbd_strings_sh[19] = "$";
  kbd_strings_sh[20] = "%";
  kbd_strings_sh[21] = "^";
  kbd_strings_sh[22] = "&";
  kbd_strings_sh[23] = "*";
  kbd_strings_sh[24] = "(";
  kbd_strings_sh[25] = ")";
  kbd_strings_sh[26] = "_";
  kbd_strings_sh[27] = "#bksp";

  kbd_strings_sh[28] = "#tab";
  kbd_strings_sh[29] = "Q";
  kbd_strings_sh[30] = "W";
  kbd_strings_sh[31] = "E";
  kbd_strings_sh[32] = "R";
  kbd_strings_sh[33] = "T";
  kbd_strings_sh[34] = "Y";
  kbd_strings_sh[35] = "U";
  kbd_strings_sh[36] = "I";
  kbd_strings_sh[37] = "O";
  kbd_strings_sh[38] = "P";
  kbd_strings_sh[39] = "+";
  kbd_strings_sh[40] = "ú";

  kbd_strings_sh[41] = "#cplk";
  kbd_strings_sh[42] = "A";
  kbd_strings_sh[43] = "S";
  kbd_strings_sh[44] = "D";
  kbd_strings_sh[45] = "F";
  kbd_strings_sh[46] = "G";
  kbd_strings_sh[47] = "H";
  kbd_strings_sh[48] = "J";
  kbd_strings_sh[49] = "K";
  kbd_strings_sh[50] = "L";
  kbd_strings_sh[51] = ":";
  kbd_strings_sh[52] = "#ent";

  kbd_strings_sh[53] = "#lsft";
  kbd_strings_sh[54] = "|"; // same key twice
  kbd_strings_sh[55] = "Z";
  kbd_strings_sh[56] = "X";
  kbd_strings_sh[57] = "C";
  kbd_strings_sh[58] = "V";
  kbd_strings_sh[59] = "B";
  kbd_strings_sh[60] = "N";
  kbd_strings_sh[61] = "M";
  kbd_strings_sh[62] = "<";
  kbd_strings_sh[63] = ">";
  kbd_strings_sh[64] = "?";
  kbd_strings_sh[65] = "#up";
  kbd_strings_sh[66] = "#rsft";

  kbd_strings_sh[67] = "#fn";
  kbd_strings_sh[68] = "#ctrl";
  kbd_strings_sh[69] = "#zzz";
  kbd_strings_sh[70] = "#alt";
  kbd_strings_sh[71] = "#brk";
  kbd_strings_sh[72] = " ";
  kbd_strings_sh[73] = "#menu";
  kbd_strings_sh[74] = "{";
  kbd_strings_sh[75] = "}";
  kbd_strings_sh[76] = "\"";
  kbd_strings_sh[77] = "#left";
  kbd_strings_sh[78] = "#dn";
  kbd_strings_sh[79] = "#right";
}


void init_kbd_strings_alt() {
  kbd_strings_alt[0] = "#esc";
  kbd_strings_alt[1] = "#f1";
  kbd_strings_alt[2] = "#f2";
  kbd_strings_alt[3] = "#f3";
  kbd_strings_alt[4] = "#f4";
  kbd_strings_alt[5] = "#f5";
  kbd_strings_alt[6] = "#f6";
  kbd_strings_alt[7] = "#f7";
  kbd_strings_alt[8] = "#f8";
  kbd_strings_alt[9] = "#f9";
  kbd_strings_alt[10] = "#f10";
  kbd_strings_alt[11] = "#nmlk";
  kbd_strings_alt[12] = "#prtscr";
  kbd_strings_alt[13] = "#ins";
  kbd_strings_alt[14] = "#del";

  kbd_strings_alt[15] = "`";
  kbd_strings_alt[16] = "+";
  kbd_strings_alt[17] = "ě";
  kbd_strings_alt[18] = "š";
  kbd_strings_alt[19] = "č";
  kbd_strings_alt[20] = "ř";
  kbd_strings_alt[21] = "ž";
  kbd_strings_alt[22] = "ý";
  kbd_strings_alt[23] = "á";
  kbd_strings_alt[24] = "í";
  kbd_strings_alt[25] = "é";
  kbd_strings_alt[26] = "=";
  kbd_strings_alt[27] = "#bksp";

  kbd_strings_alt[28] = "#tab";
  kbd_strings_alt[29] = "";
  kbd_strings_alt[30] = "|";
  kbd_strings_alt[31] = "€";
  kbd_strings_alt[32] = "¶";
  kbd_strings_alt[33] = "ŧ";
  kbd_strings_alt[34] = "←";
  kbd_strings_alt[35] = "↓";
  kbd_strings_alt[36] = "→";
  kbd_strings_alt[37] = "ø";
  kbd_strings_alt[38] = "þ";
  kbd_strings_alt[39] = "[";
  kbd_strings_alt[40] = "]";

  kbd_strings_alt[41] = "#cplk";
  kbd_strings_alt[42] = "~";
  kbd_strings_alt[43] = "đ";
  kbd_strings_alt[44] = "Đ";
  kbd_strings_alt[45] = "[";
  kbd_strings_alt[46] = "]";
  kbd_strings_alt[47] = "`";
  kbd_strings_alt[48] = "'";
  kbd_strings_alt[49] = "ł";
  kbd_strings_alt[50] = "Ł";
  kbd_strings_alt[51] = "$";
  kbd_strings_alt[52] = "#ent";

  kbd_strings_alt[53] = "#lsft";
  kbd_strings_alt[54] = "|"; // same key twice
  kbd_strings_alt[55] = "°";
  kbd_strings_alt[56] = "#";
  kbd_strings_alt[57] = "&";
  kbd_strings_alt[58] = "@";
  kbd_strings_alt[59] = "{";
  kbd_strings_alt[60] = "}";
  kbd_strings_alt[61] = "^";
  kbd_strings_alt[62] = "<";
  kbd_strings_alt[63] = ">";
  kbd_strings_alt[64] = "*";
  kbd_strings_alt[65] = "#up";
  kbd_strings_alt[66] = "#rsft";

  kbd_strings_alt[67] = "#fn";
  kbd_strings_alt[68] = "#ctrl";
  kbd_strings_alt[69] = "#zzz";
  kbd_strings_alt[70] = "#alt";
  kbd_strings_alt[71] = "#brk";
  kbd_strings_alt[72] = " ";
  kbd_strings_alt[73] = "#menu";
  kbd_strings_alt[74] = "/";
  kbd_strings_alt[75] = "]";
  kbd_strings_alt[76] = "'";
  kbd_strings_alt[77] = "#left";
  kbd_strings_alt[78] = "#dn";
  kbd_strings_alt[79] = "#right";
}


void init_kbd_strings_nmlk() {
  kbd_strings_nmlk[22] = "7";
  kbd_strings_nmlk[23] = "8";
  kbd_strings_nmlk[24] = "9";
  kbd_strings_nmlk[25] = "*";


  kbd_strings_nmlk[35] = "4";
  kbd_strings_nmlk[36] = "5";
  kbd_strings_nmlk[37] = "6";
  kbd_strings_nmlk[38] = "-";

  kbd_strings_nmlk[48] = "1";
  kbd_strings_nmlk[49] = "2";
  kbd_strings_nmlk[50] = "3";
  kbd_strings_nmlk[51] = "+";

  kbd_strings_nmlk[61] = "0";
  kbd_strings_nmlk[62] = ",";
  kbd_strings_nmlk[63] = ".";
  kbd_strings_nmlk[64] = "/";
}

void init_kbd_strings_czlk() {
  kbd_strings_czlk[16] = "+";
  kbd_strings_czlk[17] = "ě";
  kbd_strings_czlk[18] = "š";
  kbd_strings_czlk[19] = "č";
  kbd_strings_czlk[20] = "ř";
  kbd_strings_czlk[21] = "ž";
  kbd_strings_czlk[22] = "ý";
  kbd_strings_czlk[23] = "á";
  kbd_strings_czlk[24] = "í";
  kbd_strings_czlk[25] = "é";
}
