/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rdrazsky <rdrazsky@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 16:38:21 by rdrazsky      #+#    #+#                 */
/*   Updated: 2021/11/11 14:33:34 by rdrazsky      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*frst_element;
	t_list	*element;

	if (!lst)
		return (NULL);
	element = ft_lst_new((*f)(lst->content));
	if (!element)
		return (NULL);
	frst_element = element;
	lst = lst->next;
	while (lst)
	{
		element->next = ft_lst_new((*f)(lst->content));
		if (!element->next)
		{
			ft_lst_clear(&frst_element, del);
			return (NULL);
		}
		element = element->next;
		lst = lst->next;
	}
	element->next = NULL;
	return (frst_element);
}
