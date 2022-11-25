========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : WINGEX
========================================================================

AppWizard has generated this WINGEX application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your WINGEX application.


WINGEX.MAK
    This project file is compatible with the Visual C++ Workbench.

    It is also compatible with the NMAKE program provided with the
    Professional Edition of Visual C++.

    To build a debug version of the program from the MS-DOS prompt, type
	nmake DEBUG=1 /f WINGEX.MAK
    or to build a release version of the program, type
	nmake DEBUG=0 /f WINGEX.MAK

WINGEX.H
    This is the main include file for the application.  It includes other
    project specific includes (including RESOURCE.H) and declares the
    CWingexApp application class.

WINGEX.CPP
    This is the main application source file that contains the application
    class CWingexApp.

WINGEX.RC
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited with App Studio.

RES\WINGEX.ICO
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file WINGEX.RC.

RES\WINGEX.RC2
    This file contains resources that are not edited by App Studio.  Initially
    this contains a VERSIONINFO resource that you can customize for your
    application.  You should place other non-App Studio editable resources
    in this file.

WINGEX.DEF
    This file contains information about the application that must be
    provided to run with Microsoft Windows.  It defines parameters
    such as the name and description of the application, and the size
    of the initial local heap.  The numbers in this file are typical
    for applications developed with the Microsoft Foundation Class Library.
    The default stack size can be adjusted by editing the project file.

WINGEX.CLW
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to generate and edit message maps and dialog data
    maps and to generate prototype member functions.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MAINFRM.H, MAINFRM.CPP
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.


/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

WINGEDOC.H, WINGEDOC.CPP - the document
    These files contain your CWingexDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CWingexDoc::Serialize).

WINGEVW.H, WINGEVW.CPP - the view of the document
    These files contain your CWingexView class.
    CWingexView objects are used to view CWingexDoc objects.

    




/////////////////////////////////////////////////////////////////////////////
Other standard files:

STDAFX.H, STDAFX.CPP
    These files are used to build a precompiled header (PCH) file
    named STDAFX.PCH and a precompiled types (PCT) file named STDAFX.OBJ.

RESOURCE.H
    This is the standard header file, which defines new resource IDs.
    App Studio reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
