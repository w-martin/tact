News
====

## v0.3

Made testing optional through a cmake flag: "cmake -D TESTING=ON .."

## v0.2

Input module completed.   
Use the CompleteFilteredBundle pipe class to process an entire corpus directory from plain text or XML to a feature map, then save the resulting FeatureCorpus to cache it for later.  
Example code:  
````C++
auto_ptr< Corpus > corpus = auto_ptr< Corpus >(new Corpus("corpusDirectory", DOCUMENT_TYPE_BASIC));
corpus = CompleteFilteredBundle("stopwordsFile").pipe(corpus);
FeatureCorpusIO::save((FeatureCorpus *) corpus.get());
````

## v0.1.2

Changed project name to tact.  

## v0.1.1

Changed license to GPLv3.  

