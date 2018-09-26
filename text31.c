#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node_ {
    double    conf;
    int    expn;

    struct Node_* next;
}*node, Node;

node PlinkCreate( char x[] );

node AddPolyn( node ha, node hb );

int Compare( node a, node b );

void ShoList( node ha );

int main()
{
    char    a[201], b[201];
    node    ha, hb;
    while ( gets( a ) != NULL )
    {
        gets( b );
        ha    = PlinkCreate( a );
        hb    = PlinkCreate( b );
        ha = AddPolyn( ha, hb );
        ShoList( ha );
    }

    return(0);
}

node PlinkCreate( char x[] )
{
    node    head    = (node) malloc( sizeof(Node) );
    node    q    = head;
    head->next = NULL;
    int length_ = strlen( x );

    int    i = 0, d = 0;
    char    cNum[100], eNum[100];

    while ( i < length_ )
    {
        d = 0;
        node p = (node) malloc( sizeof(Node) );
        while ( x[i] == ' ' && i < length_ )
            i++;
        while ( x[i] != ' ' && i < length_ )
            cNum[d++] = x[i++];
        cNum[d] = '\0';
        p->conf = atof( cNum );
        d = 0;
        while ( x[i] == ' ' && i < length_ )
            i++;
        while ( x[i] != ' ' && i < length_ )
            eNum[d++] = x[i++];
        eNum[d] = '\0';
        p->expn = atoi( eNum );
        q->next = p;
        p->next = NULL;
        q    = q->next;
    }
    return(head);
}

node AddPolyn( node ha, node hb )
{
    int    c;
    double    sum;
    node    HA, term, term1, term2;
    HA = ha;
    while ( ha->next != NULL && hb->next != NULL )
    {
        c = Compare( ha->next, hb->next );
        switch ( c )
        {
        case 0: {
            term        = hb->next;
            hb->next    = hb->next->next;
            term->next    = ha->next;
            ha->next    = term;
            ha = ha->next;
            break;
        }

        case 1: {
            sum = ha->next->conf + hb->next->conf;
            if ( sum == 0.0 )
            {
                term1    = ha->next;
                term2    = hb->next;

                ha->next    = ha->next->next;
                hb->next    = hb->next->next;
                free( term1 );
                free( term2 );
            }else  {
                ha->next->conf = sum;
                term2        = hb->next;
                hb->next    = hb->next->next;
                free( term2 );
                ha = ha->next;
            }
            break;
        }

        case 2: {
            ha=ha->next;
            break;
        }
        }
    }

    if ( hb->next == NULL )
    {
        return(HA);
    } else{
        ha->next = hb->next;
        free( hb );
        return(HA);
    }
}

int Compare( node a, node b )
{
    if ( a->expn < b->expn )
        return(0);
    else
    if ( a->expn == b->expn )
        return(1);
    else
        return(2);
}

void ShoList( node ha )
{
    node p = ha->next;
    {
        while ( p != NULL )
        {
            printf( "%0.lf %d ", p->conf, p->expn );
            p = p->next;
        }
    }
    printf( "\n" );
}
