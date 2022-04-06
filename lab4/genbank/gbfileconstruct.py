def findme():
    fh = open('NM000207.gb')
    keyword = input('Enter the keyword: ')
    next = {'DEFINITION':'ACCESSION', 'ACCESSION':'VERSION','CDS':'sig_peptide',
            'gene            ':'exon            1..42','ORGANISM':'REFERENCE'}
    if keyword.lower() == 'gene' : 
        keyword = 'gene            '
    else: keyword = keyword.upper()
    
    all = fh.read()
    stp = all.find(keyword)
    end = all.find(next[keyword],stp)
    val = all[stp:end]
    print(val)


    