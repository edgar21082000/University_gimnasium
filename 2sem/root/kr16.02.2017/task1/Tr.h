struct Tr{
	int val;
	int key[10];
	struct Tr * left;
	struct Tr * right;
	};

struct Tr * Tr_Add(int x, struct Tr * cur);
void  Tr_Prn(struct Tr * cur);
	