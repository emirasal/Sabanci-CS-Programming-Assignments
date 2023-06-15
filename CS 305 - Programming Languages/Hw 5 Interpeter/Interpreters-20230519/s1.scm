(define s1 (lambda (e)
   (cond
      ( (number? e) e)
      ( else (error "s1: cannot evaluate --> " e)))
))
