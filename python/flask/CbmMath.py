#-*- coding:utf-8 -*-
#!/usr/bin/env python

import math

def DifficultEval1(decay_alpha):
    if decay_alpha < 0.003:
        return 1
    elif decay_alpha < 0.05:
        return 2
    else:
        return 3

def DifficultEval2(permeability_lambda):
    if permeability_lambda > 10:
        return 1
    elif permeability_lambda > 0.1:
        return 2
    else:
        return 3

def DifficultEvalHelper(k1, k2):
    difficult_eval_result_dict = [1, 4, 5, 4, 2, 6, 5, 6, 3]
    if k1 < 1 or k1 > 3 or k2 < 1 or k2 > 3:
        return 0
    else:
        return difficult_eval_result_dict[k1 * 3 + k2 - 4]

def PermeabilityString(permeability_k):
    if permeability_k < 5:
        return "����ú��"
    elif permeability_k < 20:
        return "����ú��"
    else:
        return "����ú��"

def EvalDifficultString(eval):
    eval_difficult_string = ["���׳��", "���Գ��", "���ѳ��", "���׳��~���Գ��", "���׳��~���ѳ��", "���Գ��~���ѳ��"]
    if eval < 1 or eval > 6:
        return "NULL"
    else:
        return eval_difficult_string[eval - 1]