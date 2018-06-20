#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this=(ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}

/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param this ArrayList* Pointer to arrayListok
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement)
{
    int returnAux = -1;
    int tam;
    int flag=0;
    void* aux;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size == this->reservedSize)
        {
            aux = realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
            if(aux!=NULL)
            {
                this->pElements = aux;
                this->reservedSize += AL_INCREMENT;
            }
            else
            {
                flag = 1;
            }
        }
         if(flag==0)
        {
            tam = this->size;
            this->pElements[tam] = pElement;
            this->size++;

            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this->pElements);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Returns size of the arrayList
 * \param this ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [this is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}

/** \brief  Get an element by index
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [this is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index)
{
    void* returnAux = NULL;

    if(this!=NULL && (index < this->size && index >= 0))
    {
        returnAux = this->pElements[index];
    }

    return returnAux;
}

/** \brief  Find if this contains at least one element pElement
 * \param this ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i<this->size; i++)
        {
            returnAux = 0;

            if(this->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Set a element in this at index position
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    int auxInt;

    if(this!=NULL && pElement!=NULL && (index <= this->size && index >= 0))
    {
        if(index==this->size)
        {
            auxInt = this->add(this, pElement);
            if(auxInt == 0)
            {
                returnAux = 0;
            }
        }
        else
        {
            this->pElements[index] = pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief  Remove an element by index
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && (index < this->size && index >= 0))
    {
        for(i=index; i<this->size; i++)
        {
              this->pElements[i] = this->pElements[i+1];
        }
        this->size--;
        returnAux = 0;
     }

    return returnAux;
}

/** \brief Removes all of the elements from this list
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        this->size = 0;

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Returns an array containing all of the elements in this list in proper sequence
 *  \param this ArrayList* Pointer to arrayList
 *  \return ArrayList* Return  (NULL) if Error [this is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this!=NULL)
    {
        returnAux = al_newArrayList();

        returnAux->size = this->size;
        returnAux->reservedSize = this->reservedSize;

         for(i=0; i<this->size; i++)
        {
            returnAux->pElements[i] = this->pElements[i];
        }
    }
    return returnAux;
}

/** \brief Inserts the element at the specified position
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL && (index <= this->size && index >= 0))
    {
        if(this->size == this->reservedSize)
        {
            this->reservedSize += AL_INCREMENT;
        }
        for(i=index+1; i<this->size; i++)
        {
            this->pElements[i] = this->pElements[i+1];
        }
        this->pElements[index] = pElement;
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Returns the index of the first occurrence of the specified element
 * \param this ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i, contador=0;

    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i<this->size; i++)
        {
            if(this->pElements[i] == pElement)
            {
                returnAux = contador;
                break;
            }
            contador++;
        }
    }
    return returnAux;
}

/** \brief Returns true if this list contains no elements.
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else if(this->size > 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Remove the item at the given position in the list, and return it.
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [this is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    int i;

    if(this!=NULL && (index < this->size && index >= 0))
    {
        returnAux = this->pElements[index];

        for(i=index; i<this->size; i++)
        {
            this->pElements[i] = this->pElements[i+1];
        }

        this->size--;
    }

    return returnAux;
}

/** \brief Returns a new arrayList with a portion of this between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param this ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [this is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* arrayAux = NULL;
    int i, flagAdd;

    if(this!=NULL)
    {
        arrayAux = al_newArrayList();

        if(arrayAux != NULL)
        {
            if(from>=0 && to<=this->size && from<to)
            {
                for(i=from; i<to; i++)
                {
                    flagAdd = arrayAux->add(arrayAux, this->pElements[i]);
                    if(flagAdd != 0)
                    {
                        arrayAux = NULL;
                        break;
                    }
                }
            }
            else
            {
                arrayAux = NULL;
            }
        }
    }
    return arrayAux ;
}

/** \brief Returns true if this list contains all of the elements of this2
 * \param this ArrayList* Pointer to arrayList
 * \param this2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this or this2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i;

    if(this2!=NULL && this!=NULL)
    {
        for(i=0; i<this->size; i++)
        {
            if(this->pElements[i] == this2->pElements[i])
            {
                returnAux = 1;
            }
            else
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [this or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int retornoFunc, i, j;
    void* auxElements;

    if(this!=NULL && pFunc!=NULL && (order == 1 || order == 0))
    {
        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {
                if(order == 1)
                {
                   retornoFunc = pFunc(this->pElements[i], this->pElements[j]);
                   if(retornoFunc > 0)
                   {
                       auxElements = this->pElements[i];
                       this->pElements[i] = this->pElements[j];
                       this->pElements[j] = auxElements;
                   }
                }
                if(order == 0)
                {
                    retornoFunc = pFunc(this->pElements[i], this->pElements[j]);
                    if(retornoFunc < 0)
                    {
                        auxElements = this->pElements[i];
                        this->pElements[i] = this->pElements[j];
                        this->pElements[j] = auxElements;
                    }
                }
            }
        }
         returnAux = 0;
    }
    return returnAux;
}

/** \brief Increment the number of elements in this in AL_INCREMENT elements.
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void* aux;

    if(this!=NULL)
    {
        aux = realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
        if(aux!=NULL)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && (index <= this->size && index >= 0))
    {
        if(this->size == this->reservedSize)
        {
            this->reservedSize += AL_INCREMENT;
        }
        for(i=index+1; i<this->size; i++)
        {
            this->pElements[i] = this->pElements[i+1];
        }
        this->size++;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && (index <= this->size && index >= 0))
    {
        for(i=index; i<this->size; i++)
        {
            this->pElements[i] = this->pElements[i+1];
        }

        this->size--;
        returnAux = 0;
    }
    return returnAux;
}

