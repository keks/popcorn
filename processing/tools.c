#include "tools.h"


/* --- Setup --- */

void setupMixer2ch(mixer2ch *m) { /* set default static values for new 2 channel mixer */
	m->val = 0;

	m->act1 = gBools + 0;
	m->act2 = gBools + 0;

	m->vol1.val = defValues + 1;
	setupParam(&(m->vol1));

	m->vol2.val = defValues + 1;
	setupParam(&(m->vol2));

	m->input1.val = defValues + 0;
	setupParam(&(m->input1));

	m->input2.val = defValues + 0;
	setupParam(&(m->input2));
}


/* --- Computing --- */

void compMixer2ch(mixer2ch *m) { /* compute current value of a 2 channel mixer */
	m->val = 0;

	if (*(m->act1) == 1) m->val += compParam(&(m->input1)) * compParam(&(m->vol1));
	if (*(m->act2) == 1) m->val += compParam(&(m->input2)) * compParam(&(m->vol2));
}
