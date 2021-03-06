/*
 *  Created by Martin Mroz on 3/21/15.
 *
 *  The author of the original program disclaims copyright.
 *  D language support Copyright (GPL) Serge Vakulenko <serge@vak.ru>.
 *  Copyright (GPL) (c) 2015 Martin Mroz <martinmroz@gmail.com>
 *  See LICENSE for additional information.
 */

#ifndef __lemon_build_h__
#define __lemon_build_h__

#include "lemon.h"

#include "struct.h"

/*
 ** Routines to construction the finite state machine for the LEMON
 ** parser generator.
 */

/**
 * Find a precedence symbol of every rule in the grammar.
 *
 * Those rules which have a precedence symbol coded in the input
 * grammar using the "[symbol]" construct will already have the
 * rp->precsym field filled.  Other rules take as their precedence
 * symbol the first RHS symbol with a defined precedence.  If there
 * are not RHS symbols with a defined precedence, the precedence
 * symbol field is left blank.
 */
void FindRulePrecedences(struct lemon *xp);

/** 
 * Find all nonterminals which will generate the empty string.
 * Then go back and compute the first sets of every nonterminal.
 * The first set is the set of all terminal symbols which can begin
 * a string generated by that nonterminal.
 */
void FindFirstSets(struct lemon *lemp);

/** 
 * Compute all LR(0) states for the grammar.  Links
 * are added to between some states so that the LR(1) follow sets
 * can be computed later.
 */
void FindStates(struct lemon *lemp);

/*
 ** Construct the propagation links
 */
void FindLinks(struct lemon *lemp);

/** 
 * Compute all followsets.
 *
 * A followset is the set of all symbols which can come immediately
 * after a configuration.
 */
void FindFollowSets(struct lemon *lemp);

/**
 * Compute the reduce actions, and resolve conflicts.
 */
void FindActions(struct lemon *lemp);

#endif /* defined(__lemon_build_h__) */
