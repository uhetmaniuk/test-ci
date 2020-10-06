\page introduction Introduction \brief Overview of functionality in \checkpoint

\tableofcontents

\section what-is What is checkpoint?

\checkpoint is a serialization and checkpointing library written in C++14.
It allows any C++ type that has a serialize method/function associated with it
to be flattened into a message ready for bitwise copying. 
DARMA/checkpoint is a general library that can be adapted for I/O or creating snapshots disk.
