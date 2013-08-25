#ifndef AST_H
#define AST_H

// Abstract syntax tree
// Maybe we should use C++

#include "StringBuffer.h"
#include "structs.h"

typedef enum StatementType_ StatementType;
enum StatementType_ {
	SIMPLE_STMT,
	BLOCK_STMT,
	WHILE_STMT,
	REPEAT_STMT,
	FORLOOP_STMT,
	TFORLOOP_STMT,
	IF_STMT,
	IF_THEN_STMT,
	IF_ELSE_STMT,
	// virtual statement, mark for JMP destination, some of the statements will be printed as label in 5.2
	JMP_DEST_STMT
};

extern const char* stmttype[];

typedef struct AstStatement_ AstStatement;
struct AstStatement_ {
	ListItem super;
	AstStatement* parent;
	StatementType type;
	char* code;
	List* sub;
	int line;
};

AstStatement* MakeSimpleStatement(char* code);
AstStatement* MakeBlockStatement();
AstStatement* MakeLoopStatement(StatementType type, char* test);
AstStatement* MakeIfStatement(char* test);

void ClearAstStatement(AstStatement* stmt, void* dummy);
void DeleteAstStatement(AstStatement* stmt);

void PrintAstStatement(AstStatement* stmt, StringBuffer* buff, int indent);

void PrintAstSub(List* sub, StringBuffer* buff, int indent);

void AddToStatement(AstStatement* stmt, AstStatement* sub);

#endif
