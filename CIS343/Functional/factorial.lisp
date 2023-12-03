(define (fac n)
        (if (= n 0)
        1
        (* n (fac (- n 1)))))



(define palindrome(str)
(cond
((null? str))
(else (string=? str (reverse(str->list))->string))))