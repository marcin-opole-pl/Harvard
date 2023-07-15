from twttr import shorten

def test_shorten():
    assert shorten('adegut') == 'dgt'
    assert shorten('TudeGeIO') == 'TdG'
    assert shorten('adegut TudeGeIO 50') == 'dgt TdG 50'
    assert shorten('This is CS50!') == 'Ths s CS50!'