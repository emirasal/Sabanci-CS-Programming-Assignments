(define s2 (lambda (e)
   (cond
      ( (number? e) e)
      ( (not (list? e)) (error "s2: cannot evaluate --> " e))
      ( (not (= (length e) 3)) (error "s2: cannot evaluate --> " e))
      ( (not (eq? (car e) '+)) (error "s2: cannot evaluate --> " e))
      ( (not (number? (cadr e))) (error "s2: cannot evaluate --> " e))
      ( (not (number? (caddr e))) (error "s2: cannot evaluate --> " e))
      ( else (+ (cadr e) (caddr e))))))
