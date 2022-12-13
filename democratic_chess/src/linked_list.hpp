#ifndef LINKED_LIST
#define LINKED_LIST

#include "control.h"

/// 
/// A l�ncolt lista egy eleme.
/// T�rol egy l�p�st, az ahhoz tartoz� t�bla �rt�k�t,
/// a l�p�s t�pus�t �s a "next" pointert.
/// Rendelkezik "==" �s "!=" oper�torokkal.
/// 
struct List_node {

	step move;
	int board_value;
	int move_type;
	List_node *next;

	bool operator==(List_node rhs) const;

	bool operator!=(List_node rhs) const;
};

/// 
/// Maga a l�ncolt lista.
/// K�t priv�t tagja van:
/// "head" : a legels� elemre mutat� pointer
/// "length" : a lista hossz�t mutatja.
/// 
class Linked_list {
public:

	int length;
	List_node *head;

	/// 
	/// Iter�tor oszt�ly, amely a lista haszn�lhat�s�g�t seg�ti.
	/// Egy tagja van, ami a lista egy elem�re mutat� pointer.
	/// 
	class Iterator {

		List_node *node;

	public:

		Iterator(List_node *element = NULL) :node(element) {}

		Iterator& operator++() { if (node != NULL) node = node->next; return *this; }

		Iterator operator++(int) { Iterator masolat = *this; ++(*this); return masolat; }

		step get_Move() { return node->move; }

		int get_Move_type() { return node->move_type; }

		int get_Board_value() { return node->board_value; }

		List_node* get_Next() { return node->next; }

		List_node get_Node() { return *node; }

		void set_Next(List_node* next) { node->next = next; }

		bool operator==(Iterator rhs) const { return node == rhs.node; }

		bool operator!=(Iterator rhs) const { return node != rhs.node; }
	};

	Linked_list() :length(0), head(NULL) {}

	int get_Length() { return length; }

	bool is_Empty() { return length == 0; }

	/// 
	/// A lista fel�p�t�s��rt felel�s.
	/// A lista v�g�hez f�zi az elemeket.
	/// 
	void add(step move, int board_value, int move_type);

	/// 
	/// Visszat�r a lista legutols� elem�vel.
	/// 
	List_node* last_Move();

	/// 
	/// Visszat�r a lista legmagasabb �rt�kkel rendelkez� elem�vel.
	/// 
	List_node get_Max();

	/// 
	/// Visszat�r a lista legalacsonabb �rt�kkel rendelkez� elem�vel.
	/// 
	List_node get_Min();

	/// 
	/// Kit�rli a list�t.
	/// 
	void delete_list();

	/// 
	/// Ki�rja a list�t tagonk�nt, minden bels� v�ltoz�t.
	/// 
	void print_List();

	Iterator begin() { return Iterator(head); }

	Iterator end() { return Iterator(NULL); }

	~Linked_list();
};

#endif
