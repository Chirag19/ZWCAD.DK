(defun c:drawline()
 (setq linelist '((0 . "LINE") (8 . "0") (410 . "Model") (62 . 3) (10 0 0 0) (11 100 100 0)))
 (entmake linelist)
)