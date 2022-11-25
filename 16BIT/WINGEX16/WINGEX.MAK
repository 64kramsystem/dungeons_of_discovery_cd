# Microsoft Visual C++ generated build script - Do not modify

PROJ = WINGEX
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\MSVC\WINGEX\
USEMFC = 1
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = /YcSTDAFX.H
CUSEPCHFLAG = 
CPPUSEPCHFLAG = /YuSTDAFX.H
FIRSTC =             
FIRSTCPP = STDAFX.CPP  
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W3 /Zi /AL /Od /D "_DEBUG" /FR /GA /Fd"WINGEX.PDB" 
CFLAGS_R_WEXE = /nologo /Gs /G2 /W3 /AL /O1 /D "NDEBUG" /FR /GA 
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = lafxcwd oldnames libw llibcew commdlg.lib shell.lib 
LIBS_R_WEXE = lafxcw oldnames libw llibcew commdlg.lib shell.lib 
RCFLAGS = /nologo /z 
RESFLAGS = /nologo /t 
RUNFLAGS = 
DEFFILE = WINGEX.DEF
OBJS_EXT = 
LIBS_EXT = ..\..\WING\LIB\WING.LIB 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = STDAFX.SBR \
		WINGEX.SBR \
		MAINFRM.SBR \
		WINGEDOC.SBR \
		WINGEVW.SBR \
		CDIB.SBR


WING_DEP = 

WINGEX_RCDEP = c:\msvc\wingex\res\wingex.ico \
	c:\msvc\wingex\res\wingex.rc2


STDAFX_DEP = c:\msvc\wingex\stdafx.h


WINGEX_DEP = c:\msvc\wingex\stdafx.h \
	c:\msvc\wingex\wingex.h \
	c:\msvc\wingex\mainfrm.h \
	c:\msvc\wingex\wingedoc.h \
	c:\msvc\wingex\wingevw.h \
	c:\wing\include\wing.h


MAINFRM_DEP = c:\msvc\wingex\stdafx.h \
	c:\msvc\wingex\wingex.h \
	c:\msvc\wingex\mainfrm.h


WINGEDOC_DEP = c:\msvc\wingex\stdafx.h \
	c:\msvc\wingex\wingex.h \
	c:\msvc\wingex\wingedoc.h


WINGEVW_DEP = c:\msvc\wingex\stdafx.h \
	c:\msvc\wingex\wingex.h \
	c:\msvc\wingex\wingedoc.h \
	c:\msvc\wingex\wingevw.h \
	c:\wing\include\wing.h


CDIB_DEP = c:\msvc\wingex\stdafx.h \
	c:\msvc\wingex\cdib.h


all:	$(PROJ).EXE $(PROJ).BSC

WINGEX.RES:	WINGEX.RC $(WINGEX_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r WINGEX.RC

STDAFX.OBJ:	STDAFX.CPP $(STDAFX_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c STDAFX.CPP

WINGEX.OBJ:	WINGEX.CPP $(WINGEX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINGEX.CPP

MAINFRM.OBJ:	MAINFRM.CPP $(MAINFRM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c MAINFRM.CPP

WINGEDOC.OBJ:	WINGEDOC.CPP $(WINGEDOC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINGEDOC.CPP

WINGEVW.OBJ:	WINGEVW.CPP $(WINGEVW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c WINGEVW.CPP

CDIB.OBJ:	CDIB.CPP $(CDIB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c CDIB.CPP


$(PROJ).EXE::	WINGEX.RES

$(PROJ).EXE::	STDAFX.OBJ WINGEX.OBJ MAINFRM.OBJ WINGEDOC.OBJ WINGEVW.OBJ CDIB.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
STDAFX.OBJ +
WINGEX.OBJ +
MAINFRM.OBJ +
WINGEDOC.OBJ +
WINGEVW.OBJ +
CDIB.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
d:\msvc15\lib\+
d:\msvc15\mfc\lib\+
..\..\WING\LIB\WING.LIB+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) WINGEX.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	WINGEX.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) WINGEX.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
