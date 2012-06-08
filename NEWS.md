News
====

## v0.2

Input module completed.   
Use the CompleteFilteredBundle pipe class to process an entire corpus directory from plain text or XML to a feature map, then save the resulting FeatureCorpus to cache it for later.  
Example code:  
````C++
auto_ptr< Corpus > corpus = CompleteInputBundle("stopwordsFile").pipe(auto_ptr< Corpus >(new Corpus("corpusDirectory", DOCUMENT_TYPE_BASIC)));
((FeatureCorpus *) corpus.get())->save("cacheDirectory");
````

## v0.1.2

Changed project name to mewt.  

## v0.1.1

Changed license to GPLv3.  

