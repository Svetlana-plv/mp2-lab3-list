#include "list.h"

#include <gtest.h>

TEST(List, can_create_list_with_positive_length) {

	ASSERT_NO_THROW(List<int> l(3));

}

TEST(List, cant_create_too_large_list) {

	ASSERT_ANY_THROW(List<int> l(MAX_LIST_SIZE+1));

}

TEST(List, cant_create_list_with_negative_length) {

	ASSERT_ANY_THROW(List<int> l(-3));

}

TEST(List, can_create_empty_list) {

	ASSERT_NO_THROW(List<int> l);

}

TEST(List, can_create_copied_list) {

	List<int> l(3);

	ASSERT_NO_THROW(List<int> l1(l));

}

TEST(List, copied_list_is_equal_to_source_one) {

	int n = 3;
	bool flag = true;
	List<int> l1(n);
	List<int> l2(l1);
	for (int i = 0; i < n; i++) {
		if (l1[i] != l2[i]) {
			flag = false;
		}
	}

	EXPECT_TRUE(flag);
}

TEST(List, copied_list_has_its_own_memory) {

	int n = 3;
	List<int> l1(n);
	List<int> l2(l1);

	EXPECT_NE(l1.begin(), l2.begin());
}

TEST(List, can_assign_list_to_itself) {

	List<int> l(3);

	ASSERT_NO_THROW(l=l);

}

TEST(List, can_assign_lists_of_equal_size) {

	List<int> l1(3);
	List<int> l2(3);

	ASSERT_NO_THROW(l1 = l2);

}

TEST(List, can_assign_lists_of_different_size) {

	List<int> l1(3);
	List<int> l2(5);

	ASSERT_NO_THROW(l1 = l2);

}

TEST(List, can_get_size) {

	List<int> l(3);

	EXPECT_EQ(3, l.get_size());

}

TEST(List, can_set_and_get_element) {

	List<int> l(3);
	l[1] = 5;

	EXPECT_EQ(5, l[1]);

}

TEST(List, can_print_list_correct) {

	List<int> l(3);
	l[1] = 5;

	ASSERT_NO_THROW(l.print());

}

TEST(List, can_clear_list_correct) {

	List<int> l(3);
	l.clear();

	EXPECT_EQ(l.begin(), nullptr);

}

TEST(List, cleared_list_size_equal_to_zero) {

	List<int> l(3);
	l.clear();

	EXPECT_EQ(l.get_size(), 0);

}

TEST(List, method_empty_return_true_for_empty_list) {

	List<int> l;

	EXPECT_TRUE(l.empty());

}

TEST(List, can_insert_after_correct) {

	int n = 3;
	List<int> l(n);

	l.insert_after(5, l.begin());

	EXPECT_EQ(l[1], 5);

}

TEST(List, insert_after_change_list_size) {

	int n = 3;
	List<int> l(n);

	l.insert_after(5, l.begin());

	EXPECT_EQ(l.get_size(), n + 1);

}

TEST(List, can_insert_front_correct) {

	int n = 3;
	List<int> l(n);

	l.insert_front(5);

	EXPECT_EQ(l[0], 5);

}

TEST(List, insert_front_change_list_size) {

	int n = 3;
	List<int> l(n);

	l.insert_front(5);

	EXPECT_EQ(l.get_size(), n + 1);

}

TEST(List, can_erase_after_correct) {

	int n = 3;
	List<int> l(n);
	l[2] = 5;

	l.erase_after(l.begin());

	EXPECT_EQ(l[1], 5);

}

TEST(List, erase_after_change_list_size) {

	int n = 3;
	List<int> l(n);
	l[2] = 5;

	l.erase_after(l.begin());

	EXPECT_EQ(l.get_size(), n-1);

}

TEST(List, can_erase_front_correct) {

	int n = 3;
	List<int> l(n);
	l[1] = 5;

	l.erase_front();

	EXPECT_EQ(l[0], 5);

}

TEST(List, erase_front_change_list_size) {

	int n = 3;
	List<int> l(n);
	l[1] = 5;

	l.erase_front();

	EXPECT_EQ(l.get_size(), n - 1);

}


// move semantic tests

TEST(List, can_move_list_using_move_constructor) {

	List<int> l(3);

	ASSERT_NO_THROW(List<int> l1(std::move(l)));
}

TEST(List, moved_list_is_empty_after_using_move_constructor) {

	List<int> l1(3);
	List<int> l2(std::move(l1));

	EXPECT_EQ(l1.get_size(), 0);
}

TEST(List, can_assign_list_using_move_operator) {

	List<int> l1(3);
	List<int> l2;

	ASSERT_NO_THROW(l2 = std::move(l1));
}

TEST(List, moved_list_is_empty_after_using_move_operator) {

	List<int> l1(3);
	List<int> l2;

	l2 = std::move(l1);

	EXPECT_EQ(l1.get_size(), 0);
}

TEST(List, check_task_10) {

	List<int> l(3);
	l[0] = 1;
	l[1] = 2;
	l[2] = 3;

	l.task_10();

	EXPECT_EQ(l[2], 1);
}
