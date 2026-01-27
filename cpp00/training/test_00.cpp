/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:26:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/26 17:49:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	g_var = 1;
int	f(void) {return 2;}

namespace Foo {

	int	g_var = 3;
	int f(void) {return 4;}
}

namespace Bar {

	int	g_var = 5;
	int f(void) {return 6;}
}

namespace Muf = Bar;

int main(void) {
	printf("g_var:  [%d]\n", g_var);
	printf("f():    [%d]\n", f());
	printf("g_var:  [%d]\n", Foo::g_var);
	printf("f():    [%d]\n", Foo::f());
	printf("g_var:  [%d]\n", Bar::g_var);
	printf("f():    [%d]\n", Bar::f());
	printf("g_var:  [%d]\n", Muf::g_var);
	printf("f():    [%d]\n", Muf::f());
	printf("g_var:  [%d]\n", ::g_var);
	printf("f():    [%d]\n", ::f());

	return (0);
}
