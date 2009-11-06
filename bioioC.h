#ifndef BIOIOC_H_
#define BIOIOC_H_

#include "commonC.h"

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//integer reader / writer
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

void readIntegers(FILE *file, int32_t intNumber, int32_t *iA);

void writeIntegers(FILE *file, int32_t intNumber, int32_t *iA);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//float reader / writer
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

void readDoubles(const char *string, int32_t intNumber, double *dA);


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//fasta reader/writer
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

char *fastaNormaliseHeader(const char *fastaHeader);

void fastaRead(FILE *fastaFile, struct List *seqs, struct List *seqLengths, struct List *fastaNames);

void fastaReadToFunction(FILE *fastaFile, void (*addSeq)(const char *, const char *, int32_t));

void fastaWrite(char *sequence, char *header, FILE *file);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//read in multi fasta file, and turn into a column alignment
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

struct CharColumnAlignment {
    int32_t columnNo;
    int32_t seqNo;
    char *columnAlignment;
};

char *charColumnAlignment_getColumn(struct CharColumnAlignment *charColumnAlignment, int32_t col);

void destructCharColumnAlignment(struct CharColumnAlignment *charColumnAlignment);

struct CharColumnAlignment *multiFastaRead(char *fastaFile);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//newick tree parser
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

struct BinaryTree *newickTreeParser(char *newickTreeString, float defaultDistance);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//useful sscanf functions
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

char *eatWhiteSpace(char *string);

int32_t parseInt(char **string, int32_t *j);

int32_t parseFloat(char **string, float *j);

int32_t parseString(char **string, char *cA) ;

#endif /*BIOIOC_H_*/

