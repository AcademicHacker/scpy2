#include <stdio.h>
#include "ahocorasick.h"

/* �����ؼ����б� */
AC_ALPHABET_t * allstr[] = {
    "recent", "from", "college"
};

#define PATTERN_NUMBER (sizeof(allstr)/sizeof(AC_ALPHABET_t *))

/* �����ı� */
AC_ALPHABET_t * input_text = {"She recently graduated from college"};

//*** ƥ��ʱ�Ļص�����
int match_handler(AC_MATCH_t * m, void * param)
{
    unsigned int j;

    printf ("@ %ld : %s\n", m->position, m->patterns->astring);
    /* ����0��������������1ֹͣ���� */
    return 0;
}

int main (int argc, char ** argv)
{
    unsigned int i;

    AC_AUTOMATA_t * acap;
    AC_PATTERN_t tmp_patt;
    AC_TEXT_t tmp_text;

    //*** ����AC_AUTOMATA_t�ṹ�壬�����ݻص�����
    acap = ac_automata_init();

    //*** ��ӹؼ���
    for (i=0; i<PATTERN_NUMBER; i++)
    {
        tmp_patt.astring = allstr[i];
        tmp_patt.rep.number = i+1; // optional
        tmp_patt.length = strlen(tmp_patt.astring);
        ac_automata_add (acap, &tmp_patt);
    }

    //*** ������ӹؼ���
    ac_automata_finalize (acap);

    //*** ���ô������ַ���
    tmp_text.astring = input_text;
    tmp_text.length = strlen(tmp_text.astring);

    //*** ����
    ac_automata_search (acap, &tmp_text, 0, match_handler, NULL);

    //*** �ͷ��ڴ�
    ac_automata_release (acap);
    return 0;
}