# Duplicate subtree in Binary Tree
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a binary tree, find out whether it&nbsp;contains a duplicate sub-tree of size two&nbsp;or more, or not.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1 :</strong></span></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input : </strong>
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
<strong>Output :</strong> 1
<strong>Explanation : </strong>
    2     
  /   \    
 4     5
is the duplicate sub-tree.</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><strong><span style="font-size:18px">Example 2 :</span></strong></p>

<pre style="position: relative;"><span style="font-size:18px"><strong>Input : </strong>
               1
             /   \ 
           2       3
<strong>Output: </strong>0
<strong>Explanation:</strong> There is no duplicate sub-tree 
in the given binary tree.</span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>dupSub()</strong>&nbsp;which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two&nbsp;or more, else 0.</span><br>
<span style="font-size:18px"><strong>Note:</strong> Two same leaf nodes are not considered as subtree as size of a leaf node is one.</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ length of string ≤ 100</span><br>
&nbsp;</p>
 <p></p>
            </div>