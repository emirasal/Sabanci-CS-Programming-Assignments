(define s3 (lambda (e)
   (cond
      ( (number? e) e)
      ( (not (list? e)) (error "s3: cannot evaluate --> " e))
      ( (not (= (length e) 3)) (error "s3: cannot evaluate --> " e))
      ( (not (eq? (car e) '+)) (error "s3: cannot evaluate --> " e))
      ( else (+ (s3 (cadr e)) (s3 (caddr e)))))))
