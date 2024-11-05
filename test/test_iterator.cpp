#include "list.h"

#include <gtest.h>

TEST(Iterator, can_create_iterator) {

	List<int> l(3);

	ASSERT_NO_THROW(List<int>::Iterator it(l.begin()));
}

TEST(Iterator, operator_arrow_work_correct) {

	List<int> l(3);
	l[0] = 5;
	List<int>::Iterator it = l.begin();

	EXPECT_EQ(5, it->value);
}

TEST(Iterator, can_do_postfix_increment) {

	List<int> l(3);
	l[1] = 5;
	List<int>::Iterator it = l.begin();

	EXPECT_EQ(0, (it++)->value);
}

TEST(Iterator, can_do_postfix_increment_and_value_correct) {

	List<int> l(3);
	l[1] = 5;
	List<int>::Iterator it = l.begin();

	it++;

	EXPECT_EQ(5, it->value);
}

TEST(Iterator, can_do_prefix_increment) {

	List<int> l(3);
	l[1] = 5;
	List<int>::Iterator it = l.begin();

	EXPECT_EQ(5, (++it)->value);
}

TEST(Iterator, can_do_prefix_increment_and_value_correct) {

	List<int> l(3);
	l[1] = 5;
	List<int>::Iterator it = l.begin();

	++it;

	EXPECT_EQ(5, it->value);
}

TEST(Iterator, can_compare_equal_iterators) {

	List<int> l(3);
	List<int>::Iterator it1 = l.begin();
	List<int>::Iterator it2 = l.begin();

	EXPECT_TRUE( it1 == it2 );
}

TEST(Iterator, can_compare_not_equal_iterators) {

	List<int> l(3);
	List<int>::Iterator it1 = l.begin();
	List<int>::Iterator it2 = l.begin();

	it1++;

	EXPECT_TRUE( it1 != it2 );
}

TEST(Iterator, can_get_value) {

	List<int> l(3);
	List<int>::Iterator it = l.begin();
	l[0] = 5;

	EXPECT_EQ(5, it.value());
}
